from setuptools import find_packages
from setuptools import setup

setup(
    name='dingo_hardware_config',
    version='0.0.0',
    packages=find_packages(
        include=('dingo_hardware_config', 'dingo_hardware_config.*')),
)
