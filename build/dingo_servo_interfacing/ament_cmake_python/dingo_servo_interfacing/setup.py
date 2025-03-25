from setuptools import find_packages
from setuptools import setup

setup(
    name='dingo_servo_interfacing',
    version='0.0.0',
    packages=find_packages(
        include=('dingo_servo_interfacing', 'dingo_servo_interfacing.*')),
)
