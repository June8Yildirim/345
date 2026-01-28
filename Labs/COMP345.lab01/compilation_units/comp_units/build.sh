#!/bin/bash
# Build script

echo "Building project..."
make clean
make

if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
else
    echo "❌ Build failed!"
    exit 1
fi
