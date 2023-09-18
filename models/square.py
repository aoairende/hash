#!/usr/bin/python3
""" Module defines the Rectangle Class
"""

from models.rectangle import Rectangle


class Square(Rectangle):
    """ Module Representation of Square
"""

    def __init__(self, size, x=0, y=0, id=None):
        """ Initializes a Square
        """
        super().__init__(size, size, x, y, id)

    @property
    def size(self):
        """ Size getter for Square
        """
        return self.width

    @size.setter
    def size(self, value):
        """ Size setter for Square
        """
        self.width = value
        self.height = value

    def __str__(self):
        """ String represation of square
        """
        return "[Square] ({:d}) {:d}/{:d} - {:d}".format(self.id,
                                                         self.x,
                                                         self.y,
                                                         self.width)

    def update(self, *args, **kwargs):
        """ Updates square
        """
        if len(args):
            for i, arg in enumerate(args):
                if i == 0:
                    self.id = arg
                elif i == 1:
                    self.size = arg
                elif i == 2:
                    self.x = arg
                elif i == 3:
                    self.y = arg
        else:
            for key, value in kwargs.items():
                if hasattr(self, key) is True:
                    setattr(self, key, value)

    def to_dictionary(self):
        """ Returns dictonary
        """
        return {
            "id": self.id,
            "size": self.size,
            "x": self.x,
            "y": self.y
        }
