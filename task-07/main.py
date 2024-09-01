import click
import requests
from bs4 import BeautifulSoup
import os
from imdb import IMDb

@click.command()
@click.option('-l', '--language', default=None, help='Filter subtitles by language')
@click.option('-o', '--output', default=None, help='Specify the output folder for the subtitles')
@click.option('-s', '--file-size', default=None, help='Filter subtitles by movie file size')
@click.option('-b', '--batch-download', is_flag=True, help='Enable batch mode for a directory')
@click.argument('file_or_directory')

def download_subtitles(language, output, file_size, batch_download, file_or_directory):
    """ 
    CLI tool to download subtitles for an mp4 file or a directory of files. 
    """
   
    click.echo(f"Processing your file: {file_or_directory}")
    click.echo(f"Language: {language}, Output: {output}, File Size: {file_size}")
    
    imdb_id = get_imdb_id(file_or_directory)
    
    subtitles = scrape_subtitles(imdb_id=imdb_id, file_size=file_size, language=language)
    chosen_subtitle = prompt_for_subtitle(subtitles)
    if chosen_subtitle:
        download_subtitle(chosen_subtitle, output)
    
def get_imdb_id(file_path):
    movie_title = extract_title_from_filename(file_path)
    im = IMDb()
    results = im.search_movie(movie_title)
    
    if results:
        return results[0].movieID
    else:
        click.echo('IMDb ID not found. Check the file name or the code.')
        return None
    
def extract_title_from_filename(file_path):
    base_name = os.path.basename(file_path)
    title = os.path.splitext(base_name)[0]
    
    title = title.replace('.', ' ').replace('_', ' ')
    
    return title

def scrape_subtitles(imdb_id=None, file_size=None, language='eng'):
    if imdb_id:
        url = f"https://www.opensubtitles.org/en/search/sublanguageid-{language}/imdbid-{imdb_id}"
    else:
        raise ValueError('IMDb ID is required.')
    
    response = requests.get(url)
    if response.status_code != 200:
        print(f'Failed to fetch subtitles. Status code: {response.status_code}')
        return []
    
    soup = BeautifulSoup(response.text, 'html.parser')
    subtitles = []
    
    for subtitle in soup.find_all('tr', class_='change'):
        title = subtitle.find('a', class_='bnone').text.strip()
        download_count = int(subtitle.find('td', class_='sb_dl_count').text.strip())
        download_link = subtitle.find('a', class_='bnone')['href']
        
        subtitles.append({
            'title': title,
            'download_count': download_count,
            'download_link': download_link
        })
        
    subtitles = sorted(subtitles, key=lambda x: x['download_count'], reverse=True)
    
    return subtitles

def prompt_for_subtitle(subtitles):
    if not subtitles:
        print("No subtitles found.")
        return None
    
    print('\nAvailable Subtitles:')
    for idx, subtitle in enumerate(subtitles):
        print(f"{idx + 1}. {subtitle['title']} (Downloaded {subtitle['download_count']} times)")
        
    choice = int(input("Enter the number of the subtitle you want to download: ")) - 1
    if 0 <= choice < len(subtitles):
        return subtitles[choice]
    else:
        print('Invalid choice.')
        return None
    
def download_subtitle(subtitle, output_folder=None):
    download_url = f"https://www.opensubtitles.org{subtitle['download_link']}"
    response = requests.get(download_url)
    
    output_path = output_folder if output_folder else 'subtitle.srt'
    with open(output_path, 'wb') as file:
        file.write(response.content)
    print('Subtitle downloaded successfully.')

if __name__ == '__main__':
    download_subtitles()
