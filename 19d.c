#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void main()
{
  /*mknod(const char *pathname, mode_t mode, dev_t dev);
  pathname -->specifies path and file name
  mode     --> speficies file mode and type of node to be created
  dev      --> for device no if mode is IF_CHR or IFBLK*/

  int fifo=mknod("fifo19d",S_IFIFO|0777,0);
  if(fifo==-1)
    perror("Error");
  else
    printf("mknod returned :%d \nSuccess\n",fifo);

}
