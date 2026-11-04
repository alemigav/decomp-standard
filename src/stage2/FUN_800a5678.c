/* FUN_800a5678
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5678  body 0x800a5678..0x800a56bf  size 72 B
 * body sha256 6632bd83aaa51b2124fc8834187e6b2f986bfbd0ffe9801a77d0768d6c9f5d1e
 * provider record sha256 3987bddc8ded4cdf4b47539f00d7adc99837a1679c11a80fc8758adf3eda178e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a5678(void)

{
  if (DAT_80135cac == 0) {
    osRecvMesg(0x80143fb0,0,1);
  }
  DAT_80135cac = DAT_80135cac + 1;
  return;
}
