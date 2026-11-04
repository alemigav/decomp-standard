/* FUN_80030fd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030fd0  body 0x80030fd0..0x8003104f  size 128 B
 * body sha256 d1ee191520cb825e6411c1aa72d3524a3c8493ea049bdaa85a9d7da599e2973b
 * provider record sha256 d1719488f41ebc158ca3dcddc9c480617fdd33577f35864359cf23dbbfedc484
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_80030fd0(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1[5];
  iVar2 = puVar3[1];
  if (iVar2 == 0) {
    iVar2 = (*(code *)puVar3[3])();
    if (iVar2 == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x11;
      (**(code **)*param_1)(param_1);
    }
    iVar2 = puVar3[1];
  }
  puVar3[1] = iVar2 + -1;
  uVar1 = *(undefined1 *)*puVar3;
  *puVar3 = (undefined1 *)*puVar3 + 1;
  return uVar1;
}
