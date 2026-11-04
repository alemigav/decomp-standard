/* FUN_800510d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800510d0  body 0x800510d0..0x80051103  size 52 B
 * body sha256 0a75457fa68bfe1011c45182105a087b6ecd41d537ab63ee5a77de885a31558d
 * provider record sha256 01169db8f922293df3b7a1282825f07aebadebce126a44bb8321cd7968d8da33
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800510d0(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_8010bc30 < 5) {
    iVar1 = DAT_8010bc30 * 4;
    DAT_8010bc30 = DAT_8010bc30 + 1;
    *(undefined4 *)(&DAT_8010bf90 + iVar1) = param_1;
  }
  return;
}
