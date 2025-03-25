# from setuptools._distutils.core import setup
# from catkin_pkg.python_setup import generate_distutils_setup

# d = generate_distutils_setup(
#     packages=['dingo'],
#     package_dir={'': 'src'}
# )

# setup(**d)

from setuptools import setup

package_name = 'dingo'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='your.email@example.com',
    description='A short description of your package',
    license='License of your choice',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'dingo_driver = scripts.dingo_driver:main',
        ],
    },
)