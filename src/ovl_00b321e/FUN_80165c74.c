/* FUN_80165c74
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165c74  body 0x80165c74..0x80165d0f  size 156 B
 * body sha256 3c8ba9f6959e1e72f6053a2082d775226503be0b42f4b1fb8a5d963c73cba94d
 * provider record sha256 88364294c5fc28c624edab8890ec27b610b2a633763b3054206208d852c71b37
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c74(int param_1)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = *(char *)(param_1 + 0x2cc) - 1;
  if (((*(char *)(param_1 + 0x2cc) != '\0') &&
      (*(byte *)(param_1 + 0x2cc) = bVar2, (*(byte *)(param_1 + 0x2bd) & 1) != 0)) &&
     ((bVar2 & 1) != 0)) {
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,3,uVar1 & 7);
  }
  if ((*(byte *)(param_1 + 0x2bd) & 0x80) != 0) {
    (*(code *)(&PTR_FUN_8016684c)[*(byte *)(param_1 + 0x2ba)])(param_1,param_1 + 0x2b4);
  }
  return;
}
