from setuptools import setup

package_name = 'dingo_pybullet'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    author='Your Name',
    author_email='your-email@example.com',
    maintainer='Your Name',
    maintainer_email='your-email@example.com',
    description='A ROS 2 package for running PyBullet simulation',
    license='License',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'launch_robot = scripts.launch_robot:main',
        ],
    },
)