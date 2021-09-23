build:
	gcc -Wfatal-errors \
	-std=c99 \
	./*.c \
	-I"C:\libsdl\include" \
	-I"C:\libimage\include" \
	-L"C:\libimage\lib" \
	-L"C:\libsdl\lib" \
	-lmingw32 \
	-lSDL2main \
	-lSDL2 \
	-lSDL2_image \
	-o example.exe