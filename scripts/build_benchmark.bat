:: �ۼ���: ������
:: �ۼ���: 2022/11/24

@echo off

cd ..
git submodule update --init --recursive

:: 32��Ʈ ����
cmake -S . -B build/Win32 -G"Visual Studio 17 2022" -A Win32
cmake --build build/Win32 --config Debug
cmake --build build/Win32 --config Release

:: 64��Ʈ ����
cmake -S . -B build/x64 -G"Visual Studio 17 2022" -A x64
cmake --build build/x64 --config Debug
cmake --build build/x64 --config Release

echo "���尡 ��� �Ϸ�Ǿ����ϴ�"
timeout /t 2