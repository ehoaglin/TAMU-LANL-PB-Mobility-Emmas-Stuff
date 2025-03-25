from setuptools import find_packages
from setuptools import setup

setup(
    name='dingo_control_msg',
    version='0.0.0',
    packages=find_packages(
        include=('dingo_control_msg', 'dingo_control_msg.*')),
)
