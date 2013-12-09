#! /bin/bash

for i in {1..34}
do
	./pro2.exe < input$i.txt > result$i.txt
	diff -Bbs result$i.txt output$i.txt
	rm result$i.txt
done


