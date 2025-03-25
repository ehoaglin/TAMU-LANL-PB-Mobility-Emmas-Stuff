from setuptools import find_packages
from setuptools import setup

setup(
    name='dingo_peripheral_interfacing',
    version='0.0.0',
    packages=find_packages(
        include=('dingo_peripheral_interfacing', 'dingo_peripheral_interfacing.*')),
)
