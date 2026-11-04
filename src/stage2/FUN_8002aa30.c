/* FUN_8002aa30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002aa30  body 0x8002aa30..0x8002aac7  size 152 B
 * body sha256 86f891006abdb59f4eeee5116959c32e09220f007e67638fec72decf7599c58b
 * provider record sha256 99d7b5b6e9f3c81eaf47d0927057f009066a0fa07e9c0b3bc16d9d5141b0bc13
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002aa30(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[0x5a];
  *(int *)(iVar1 + 8) = param_1[0x18];
  if (param_2 == 0) {
    if (param_1[0x10] == 0) {
      if (*(int *)(param_1[0x60] + 8) == 0) {
        *(code **)(iVar1 + 4) = FUN_8002aac8;
      }
      else {
        *(code **)(iVar1 + 4) = FUN_8002ab80;
        FUN_8002a570();
        *(undefined4 *)(iVar1 + 0x44) = 0;
        *(undefined4 *)(iVar1 + 0x48) = 0;
        *(undefined4 *)(iVar1 + 0x50) = 0;
      }
      *(undefined4 *)(iVar1 + 0x34) = 0;
      *(undefined4 *)(iVar1 + 0x38) = 0;
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)();
  }
  return;
}
