/* FUN_801621c4
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801621c4  body 0x801621c4..0x8016237b  size 440 B
 * body sha256 f51db89fb6c5adb34e184db47af5f9732cc351384d262c369b70d3d0da859474
 * provider record sha256 c0c38d4e394d3e2776c8af051570088c815581dd79d017cb951bdf3884354840
 * callees 5 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_801621c4(int param_1,undefined4 param_2)

{
  short sVar2;
  byte bVar3;
  undefined4 uVar1;
  int *piVar4;
  int iVar5;
  uint uVar6;
  short local_30;
  short local_2e;
  short local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  func_0x8008383c((int)*(short *)(param_1 + 0x66),*(undefined4 *)(param_1 + 0x70),param_2,&local_30)
  ;
  sVar2 = func_0x80032d14(0,0,(int)local_30,(int)local_2c);
  *(char *)(param_1 + 0x206) = (char)((int)((int)sVar2 + 0x100U & 0xc00) >> 10);
  local_24 = (int)local_2e;
  local_28 = (int)local_30 + *(int *)(param_1 + 0x28);
  uVar6 = 0x80000000;
  local_20 = (int)local_2c + *(int *)(param_1 + 0x30);
  iVar5 = 1 << (-(*(int *)(param_1 + 0x2c) / 0x708) & 0x1fU);
  func_0x800667d4(&local_28,10,iVar5,0x200);
  piVar4 = (int *)&DAT_800e1068;
  if (_DAT_800e1068 == 0) {
    uVar6 = 0x40000000;
  }
  else {
    func_0x800667d4(&local_28,10,iVar5,0x600);
    do {
      if ((*(ushort *)(*piVar4 + 8) & 0x200) == 0) {
        uVar6 = uVar6 | 0x20000000;
      }
      else {
        bVar3 = func_0x8006a42c(&local_28);
        if (*piVar4 == *(int *)(param_1 + 700)) {
          if ((*(byte *)(param_1 + 0x207) & 1) == 0) {
            uVar1 = func_0x8006a880(*(undefined1 *)(param_1 + 0x207));
            *(undefined4 *)(param_1 + 0x28) = uVar1;
          }
          else {
            uVar1 = func_0x8006a880(*(undefined1 *)(param_1 + 0x207));
            *(undefined4 *)(param_1 + 0x30) = uVar1;
          }
        }
        else {
          *(int *)(param_1 + 700) = *piVar4;
          if (((bVar3 ^ *(byte *)(param_1 + 0x207)) & 1) != 0) {
            *(int *)(param_1 + 700) = *piVar4;
            return (uint)bVar3;
          }
        }
      }
      piVar4 = piVar4 + 1;
    } while (*piVar4 != 0);
  }
  return uVar6;
}
