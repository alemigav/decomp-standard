/* FUN_800a861c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a861c  body 0x800a861c..0x800a8693  size 120 B
 * body sha256 fec8f0cb03c57a74fa81e2166fc05f53d974b35dc365140d507d9c99bc8af2e0
 * provider record sha256 b09f99ec0ff9242ac9c41ad3c21100e6a5bfc30ae604a6727c2eaace67f997d5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800a861c(uint param_1,char param_2,undefined1 param_3)

{
  char cVar2;
  int iVar1;
  
  if (param_2 != -1) {
    cVar2 = FUN_800ac77c(param_2,param_3);
    if ((cVar2 != '\0') && (iVar1 = FUN_800a62c0(param_1 & 0x7f,param_2,param_3), iVar1 != -1)) {
      return iVar1;
    }
  }
  return -1;
}
