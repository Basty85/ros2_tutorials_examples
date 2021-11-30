from setuptools import setup
import os
from glob import glob

package_name = 'tf2_workshop'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
         glob(os.path.join('launch', '*.launch.py')))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dis3si',
    maintainer_email='sebastian.dick@de.bosch.com',
    description='tf2_dynamic_broadcaster',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'broadcaster = tf2_workshop.broadcaster:main',
                'broadcaster_off = tf2_workshop.broadcaster_official:main',
                'listener = tf2_workshop.listener:main',
                'listener_off = tf2_workshop.listener_official:main',
                'add_fixed_frame_off = tf2_workshop.add_fixed_frame_official:main',
        ],
    },
)
