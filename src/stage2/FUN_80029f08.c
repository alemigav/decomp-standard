/* FUN_80029f08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80029f08  body 0x80029f08..0x80029fa7  size 160 B
 * body sha256 0bb158addc498f8a1caa30d3bc942d8e33ff1ad323fd76e2cdae754a03508031
 * provider record sha256 929d3baf90d541300e4f6b1db32c798363972e5b3693b5393c4a1cc49a8a16e4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80029f08(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x178);
  iVar2 = *(int *)(iVar5 + 0xc);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 7;
  }
  *(int *)(*(int *)(param_1 + 0x174) + 0x5c) =
       *(int *)(*(int *)(param_1 + 0x174) + 0x5c) + (iVar2 >> 3);
  *(undefined4 *)(iVar5 + 0xc) = 0;
  iVar2 = (**(code **)(*(int *)(param_1 + 0x174) + 8))(param_1);
  uVar1 = 0;
  if (iVar2 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x118)) {
      iVar4 = iVar5;
      do {
        *(undefined4 *)(iVar4 + 0x10) = 0;
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 4;
      } while (iVar2 < *(int *)(param_1 + 0x118));
    }
    uVar3 = *(undefined4 *)(param_1 + 0xe8);
    uVar1 = 1;
    *(undefined4 *)(iVar5 + 0x24) = 0;
    *(undefined4 *)(iVar5 + 0x20) = uVar3;
  }
  return uVar1;
}
