Set-Item -Path Env:PKG_CONFIG_PATH -Value "C:/vcpkg/installed/x64-windows/debug/lib/pkgconfig;$(Get-Item -Path Env:PKG_CONFIG_PATH).Value"
meson setup ../../build/debug --backend=ninja