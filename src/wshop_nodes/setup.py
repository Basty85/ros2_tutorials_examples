from setuptools import setup

package_name = 'wshop_nodes'

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
    maintainer='dis3si',
    maintainer_email='sebastian.dick@de.bosch.com',
    description='ex11 Tutorial small publisher',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
		'talker = wshop_nodes.minimal_publisher:main',
		'listener = wshop_nodes.minimal_subscriber:main',
        'composed = wshop_nodes.composed_nodes:main'
        ],
    },
)
