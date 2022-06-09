# This is optional file for creating assets
from PIL import Image

# Create a image
image1 = Image.new('RGB', (32,32), 'white')
# load pic
pic = image1.load()
# make checkerboard pattern of 8x8 squares
for y in range(0,32):
    for x in range(0,32):
        pic[x,y] = (0,50,100,255)

# image.show()
image1.save('assets/hero.png')

# Create a image
image2 = Image.new('RGB', (64,64), 'white')
# load pic
pic = image2.load()
# make checkerboard pattern of 8x8 squares
for y in range(0,2):
    for x in range(0,2):
        for j in range(0,32):
            for i in range(0,32):
                if (x+y)%2 == 0:
                    pic[x*32+i,y*32+j] = (100,100,100,255)
                elif (x+y)%2 == 1:
                    pic[x*32+i,y*32+j] = (211,211,211,255)

# image.show()
image2.save('assets/checkerboard.png')