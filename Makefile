default:
	@clang++ src/*.cpp -o out/out
	@out/out

run:
	@clang++ src/*.cpp -o out/out
	@out/out

build:
	@clang++ src/*.cpp -o out/out

nobuild:
	@out/out