print("Writing to 10 different files")
allfiles = []
for i in range(10):
    f = open("/tmp/output{}".format(i), "w")
    f.write("writing to file {}\n\0".format(i))
    f.flush() # force the fileio.write to happen in the loop
print("Done")
