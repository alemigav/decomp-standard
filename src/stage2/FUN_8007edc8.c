/* FUN_8007edc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007edc8  body 0x8007edc8..0x8007eecf  size 264 B
 * body sha256 f9100cdb0bc07966f76b0272fa6f2abe50c72cb4ba0422edc0e002c0c56b94f1
 * provider record sha256 3e2f61a1c85201b1d496f99d4a9ce7b4932b1980b7f7874dabfec3089d891a5e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8007ee6c) */

void FUN_8007edc8(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = DAT_8011b560;
  iVar2 = DAT_8011b54c;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined2 *)(param_1 + 500) = 0x3c;
  }
  if (*(short *)(param_1 + 500) != 0) {
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -1;
  }
  if (*(ushort *)(param_1 + 0x2ba) < 200) {
    *(undefined4 *)(param_1 + 4) = 0x10b0000;
  }
  else if ((*(short *)(param_1 + 500) < 0x1e) && (1000 < *(ushort *)(param_1 + 0x2ba))) {
    *(undefined4 *)(param_1 + 4) = 0x10d0000;
  }
  else {
    if (*(short *)(param_1 + 500) == 0) {
      *(undefined4 *)(param_1 + 4) = 0x10d0000;
    }
    if ((uVar1 < 0x5dc) && (uVar4 = 0x30, (*(uint *)(param_1 + 0x1ac) & 1) == 0)) {
      iVar2 = *(int *)(iVar2 + 0x28);
      iVar3 = *(int *)(param_1 + 0x30);
    }
    else {
      iVar2 = (int)*(short *)(param_1 + 0x260);
      iVar3 = (int)*(short *)(param_1 + 0x262);
      uVar4 = 0xffffffd0;
    }
    FUN_80032dbc(param_1,iVar2,iVar3,uVar4);
  }
  return;
}
