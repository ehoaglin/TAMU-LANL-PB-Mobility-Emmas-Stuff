from setuptools import find_packages
from setuptools import setup

setup(
    name='dingo_input_interfacing',
    version='0.0.0',
    packages=find_packages(
        include=('dingo_input_interfacing', 'dingo_input_interfacing.*')),
)
