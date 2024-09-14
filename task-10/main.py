import os
from PIL import Image, ImageDraw
import cv2

folder_path = './assets'

image_set = sorted([img for img in os.listdir(folder_path) if img.endswith('.png')])

output_image = Image.new('RGB',  (512,512), 'white')
draw = ImageDraw.Draw(output_image)

previous_coordinates = None

for current_image in image_set:
    image_path = os.path.join(folder_path, current_image)
    image = cv2.imread(image_path)
    
    if image is None:
        print(f"Error loading image: {image_path}")
        continue
    if image.mean() == 250:
        previous_coordinates = None
        continue


# balance code (could not complete)