/* FUN_8016225c
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x8016225c  body 0x8016225c..0x8016232f  size 212 B
 * body sha256 13449d35d5ea5f5bf7c9ce9cb22c4c7e14b2e798a635d8dd1d0cecdb56c58344
 * provider record sha256 bd8ae4a77e8dcdfcc23dc7fc763bc42f6b2a285f99e6f5fc2f2056af28452517
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016225c(int param_1)

{
  int iVar1;
  char cVar3;
  uint uVar2;
  
  *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 8;
  if (*(char *)(param_1 + 6) == '\0') {
    iVar1 = func_0x80036b84(param_1,1,0,0);
    if (iVar1 == 0) {
      return;
    }
    uVar2 = func_0x80033604();
    if ((uVar2 & 2) != 0) {
      cVar3 = *(char *)(param_1 + 6) + '\x01';
      goto LAB_8016231c;
    }
  }
  else {
    if (*(char *)(param_1 + 6) != '\x01') {
      return;
    }
    cVar3 = func_0x80036b84(param_1,0,0,0);
    cVar3 = *(char *)(param_1 + 6) - cVar3;
    *(char *)(param_1 + 6) = cVar3;
    if (cVar3 == '\0') {
      return;
    }
    uVar2 = func_0x80033604();
    if ((uVar2 & 2) != 0) {
      cVar3 = *(char *)(param_1 + 6) + -1;
LAB_8016231c:
      *(char *)(param_1 + 6) = cVar3;
      return;
    }
  }
  *(undefined4 *)(param_1 + 4) = 0x1010000;
  return;
}
