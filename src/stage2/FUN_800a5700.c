/* FUN_800a5700
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5700  body 0x800a5700..0x800a5727  size 40 B
 * body sha256 6e6bba1d293422ceaa48474e09aa14c5f439f5e6149003629d1bc5bbf202df2a
 * provider record sha256 10a595c9634ccc5a62c832fa2125c319293d6d9900f76cd570215f247ae43103
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a5700(void)

{
  osRecvMesg(0x80143fb0,0,1);
  return;
}
