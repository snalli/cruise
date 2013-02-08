// definitions for container module


#ifdef HAVE_CONTAINER_LIB

int scrmfs_container_init(char * info, cs_store_handle_t * cs_store_handle, cs_set_handle_t * cs_set_handle, size_t size, const char * prefix);
int scrmfs_container_finalize();
int scrmfs_container_open(cs_set_handle_t  cs_set_handle, cs_container_handle_t* ch, int fid, size_t size, const char * prefix);
int scrmfs_container_extend(cs_set_handle_t  cs_set_handle, cs_container_handle_t ch, off_t size);

int scrmfs_container_read(cs_container_handle_t ch, void * buf, size_t count, off_t offset);
int scrmfs_container_write(cs_container_handle_t ch, void * buf, size_t count, off_t offset);

/* if length is greater than reserved space,
 * reserve space up to length */
int scrmfs_fid_store_container_extend(
  int fid,                 /* file id to reserve space for */
  scrmfs_filemeta_t* meta, /* meta data for file */
  off_t length             /* number of bytes to reserve for file */
);

/* if length is shorter than reserved space,
 * give back space down to length */
int scrmfs_fid_store_container_shrink(
  int fid,                 /* file id to free space for */
  scrmfs_filemeta_t* meta, /* meta data for file */
  off_t length             /* number of bytes to reserve for file */
);

/* read data from file stored as container,
 * returns SCRMFS error code */
int scrmfs_fid_store_container_read(
  int fid,                 /* file id to read from */
  scrmfs_filemeta_t* meta, /* meta data for file */
  off_t pos,               /* position within file to read from */
  void* buf,               /* user buffer to store data in */
  size_t count             /* number of bytes to read */
);

/* write data to file stored as container,
 * returns SCRMFS error code */
int scrmfs_fid_store_container_write(
  int fid,                 /* file id to write to */
  scrmfs_filemeta_t* meta, /* meta data for file */
  off_t pos,               /* position within file to write to */
  const void* buf,         /* user buffer holding data */
  size_t count             /* number of bytes to write */
);

#endif //HAVE_CONTAINER_LIB

