CC = g++
TARGET = metaballs
OBJS = nsMetaballs.o nsGaussians.o nsRayCast.o nsShade.o nsPPM.o main.o

.C.o:
	$(CC) -c $<

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	/bin/rm *.o
