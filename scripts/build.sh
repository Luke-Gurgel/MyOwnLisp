# $1 == file
# $2 == output file
cc -std=c99 -Wall $1 -leditline -o build/$2