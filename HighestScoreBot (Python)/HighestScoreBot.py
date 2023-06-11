import pyautogui

def is_white(pixel):
    white_color = (255, 255, 255)
    return pixel == white_color

def is_brown(pixel):
    brown_color = (161, 116, 56)
    return pixel == brown_color

def is_blue(pixel):
    blue_color = (211, 247, 255)
    return pixel == blue_color

coordinates = [(888, 512), (884, 586), (1024, 512), (1035, 586)]

while True:
    pixel_colors = [pyautogui.pixel(x, y) for x, y in coordinates]
    brown_pixel = is_brown(pixel_colors[0])
    blue_pixel = is_blue(pixel_colors[0])
    white_pixel = is_white(pixel_colors[1])

    if brown_pixel and white_pixel:
        pyautogui.press('right')
    elif blue_pixel and white_pixel:
        pyautogui.press('left')
    elif is_brown(pixel_colors[2]) and is_white(pixel_colors[3]):
        pyautogui.press('left')
    elif is_blue(pixel_colors[2]) and is_white(pixel_colors[3]):
        pyautogui.press('right')
