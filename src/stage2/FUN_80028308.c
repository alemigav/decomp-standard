/* FUN_80028308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028308  body 0x80028308..0x80028327  size 32 B
 * body sha256 c804ad05336e71c242cbe59799f23a233d0d5160242279ab52ec319a9eea1dc7
 * provider record sha256 ac1871c35cfc8f4f91cb516ed43bb56586c202f7f1147d4a01a7e139b50da462
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80028308(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0x1e;
  do {
    bVar1 = iVar2 != -1;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return param_1;
}
