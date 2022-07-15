import platform

from setuptools import Extension, setup

def get_ext_modules() -> list:
    """
    获取三方模块
    Linux和Windows需要编译封装接口
    Mac由于缺乏二进制库支持无法使用
    """

    if platform.system() == "Linux":
        extra_compile_flags = [
            "-std=c++17",
            "-O3",
            "-Wno-delete-incomplete",
            "-Wno-sign-compare",
        ]
        extra_link_args = ["-lstdc++"]
        runtime_library_dirs = ["$ORIGIN"]

    elif platform.system() == "Windows":
        extra_compile_flags = ["-O2", "-MT"]
        extra_link_args = []
        runtime_library_dirs = []

    else:
        return []

    vnnsq = Extension(
        name="vnpy_nsq.api.vnnsq",
        sources=["vnpy_nsq/api/vnnsq/vnnsq/vnnsq.cpp"],
        include_dirs=["vnpy_nsq/api/include", "vnpy_nsq/api/vnnsq"],
        library_dirs=["vnpy_nsq/api/libs", "vnpy_nsq/api"],
        libraries=["HSNsqApi"],
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        language="cpp",
    )

    return [vnnsq]

    
setup(ext_modules=get_ext_modules())
