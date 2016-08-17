
import pygame
import string
import time
import os
pygame.init()
screen = pygame.display.set_mode((512,512))
background = pygame.image.load("Images/background.jpg").convert()
x_piece = pygame.image.load("Images/x.png").convert_alpha()
o_piece = pygame.image.load("Images/o.png").convert_alpha()
while True:
    try:
        #exit game
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            if event.type == pygame.MOUSEMOTION:
                mouse = pygame.mouse.get_pos()
                allchars = ''.join(chr(i) for i in xrange(256))
                identity = string.maketrans('', '')
                nondigits = allchars.translate(identity, string.digits)
                mouse_x = ((str(mouse)[0:4]).translate(identity, nondigits))
                mouse_y = ((str(mouse)[5:]).translate(identity, nondigits))
                mouse_y = int(mouse_y)
                mouse_x = int(mouse_x)
                print  "x = " + str(mouse_x) + ", y = " + str(mouse_y)
                #background picture
        screen.blit(background,(0,0))
        screen.blit(x_piece,(65,55))
        #print mouse_location
        pygame.display.update()
    except (SystemExit):
        pygame.quit()
"""
Modified Version

def mouse_quadrant():
    if event.type == pygame.MOUSEBUTTONUP:
        mouse = pygame.mouse.get_pos()
        allchars = ''.join(chr(i) for i in xrange(256))
        identity = string.maketrans('', '')
        nondigits = allchars.translate(identity, string.digits)
        mouse_x = ((str(mouse)[0:4]).translate(identity, nondigits))
        mouse_y = ((str(mouse)[5:]).translate(identity, nondigits))
        mouse_y = int(mouse_y)
        mouse_x = int(mouse_x)
        print mouse_x,mouse_y
        if (mouse_x < 170) and (mouse_y < 170) :
            print "quad 1"
            return 1
        elif (170 < mouse_x < 340) and (mouse_y < 170 ):
            print "quad 2"
            return 2
        elif (340 < mouse_x) and (mouse_y < 170):
            print "quad 3"
            return 3
        elif (mouse_x < 170) and (170 < mouse_y < 340 ):
            print "quad 4"
            return 4
        elif (170 < mouse_x < 340) and (170 < mouse_y < 340 ):
            print "quad 5"
            return 5
        elif (340 < mouse_x) and (170 < mouse_y < 340 ):
            print "quad 6"
            return 6
        elif (mouse_x < 170) and (340 < mouse_y) :
            print "quad 7"
            return 7
        elif (170 < mouse_x < 340) and (340 < mouse_y):
            print "quad 8"
            return 8
        else:
            print "quad 9"
            return 9
"""