/* FUN_800a485c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a485c  body 0x800a485c..0x800a48e3  size 136 B
 * body sha256 627c9482003834e85c6cb26b8e28169259799d1178d04d4e83ba3da1450cb725
 * provider record sha256 0411d10c16009af91d0d84161785733ef927d8e97449c363897cbc37281882d2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a485c(void)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  double dVar4;
  
  uVar1 = (uint)_DAT_80143f14;
  iVar3 = 0;
  if (uVar1 != 0) {
    pcVar2 = _DAT_80143f0c;
    do {
      if (*pcVar2 != '\0') {
        dVar4 = *(double *)(pcVar2 + 8);
        *(undefined4 *)(pcVar2 + 0x14) = *(undefined4 *)(pcVar2 + 0x10);
        if (dVar4 < 2147483648.0) {
          *(int *)(pcVar2 + 0x10) = (int)dVar4;
        }
        else {
          *(uint *)(pcVar2 + 0x10) = (int)(dVar4 - 2147483648.0) | 0x80000000;
        }
      }
      iVar3 = iVar3 + 1;
      pcVar2 = pcVar2 + 0x68;
    } while (iVar3 < (int)uVar1);
  }
  return;
}
