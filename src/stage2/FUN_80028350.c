/* FUN_80028350
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028350  body 0x80028350..0x800283af  size 96 B
 * body sha256 6e6002020dd69bd34ef2540b18aad74589f610635205d264d97c0fe60f8054a1
 * provider record sha256 f8b1c1d24c80c77ef5fa7e369ce03d0cc774e49301e94ea18f7cba7b108a131a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028350(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 1;
  do {
    iVar3 = iVar2 + -1;
    (**(code **)(*(int *)(param_1 + 4) + 0x24))(param_1,iVar2);
    iVar2 = iVar3;
  } while (0 < iVar3);
  uVar1 = 100;
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar1 = 200;
  }
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  return;
}
