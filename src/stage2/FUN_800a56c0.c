/* FUN_800a56c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a56c0  body 0x800a56c0..0x800a56ff  size 64 B
 * body sha256 df07ebeb823095f4b5d5706685536bfbb530ecdc68c7edfcc4b8992fccf42435
 * provider record sha256 55b63261a4b866960879990f19bc3e67b3a6a4efeae0a1c6a8503316a53ab6ab
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a56c0(void)

{
  if ((0 < DAT_80135cac) && (DAT_80135cac = DAT_80135cac + -1, DAT_80135cac == 0)) {
    osSendMesg(0x80143fb0,0,0);
  }
  return;
}
