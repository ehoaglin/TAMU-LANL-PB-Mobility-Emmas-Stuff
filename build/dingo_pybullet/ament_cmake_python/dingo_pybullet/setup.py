from setuptools import find_packages
from setuptools import setup

setup(
    name='dingo_pybullet',
    version='1.0.0',
    packages=find_packages(
        include=('dingo_pybullet', 'dingo_pybullet.*')),
)
