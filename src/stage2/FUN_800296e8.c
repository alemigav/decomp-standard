/* FUN_800296e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800296e8  body 0x800296e8..0x8002989b  size 436 B
 * body sha256 22535bc0d127bd586a5eed4752bd6cb852dcf483bf1e2fb4d1ff907b35ef312d
 * provider record sha256 f00119c9107eef363d19763140b3515675bc7dc39f33ad8b6a40158c065adddd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800296e8(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x58);
  param_1[0x5f] = (int)puVar1;
  *puVar1 = FUN_800293a0;
  puVar1[1] = FUN_80029648;
  if (0 < param_1[8]) {
    piVar3 = (int *)(param_1[0x2c] + 0x24);
    do {
      iVar2 = *piVar3;
      piVar3[10] = 0;
      if (iVar2 == 2) {
        puVar1[2] = FUN_8002f884;
LAB_800297e0:
        puVar1[0xc] = 0;
      }
      else if (iVar2 < 3) {
        if (iVar2 == 1) {
          puVar1[2] = &LAB_8002fbbc;
          goto LAB_800297e0;
        }
LAB_8002982c:
        *(undefined4 *)(*param_1 + 0x14) = 6;
        *(int *)(*param_1 + 0x18) = *piVar3;
LAB_80029844:
        (**(code **)*param_1)(param_1);
      }
      else if (iVar2 == 4) {
        puVar1[2] = FUN_8002f320;
        puVar1[0xc] = 0;
      }
      else {
        if (iVar2 != 8) goto LAB_8002982c;
        if (param_1[0x15] == 1) {
          puVar1[2] = FUN_8002edd0;
          puVar1[0xc] = 1;
        }
        else {
          if (param_1[0x15] != 2) {
            *(undefined4 *)(*param_1 + 0x14) = 0x28;
            goto LAB_80029844;
          }
          puVar1[2] = FUN_8002e900;
          puVar1[0xc] = 2;
        }
      }
      puVar1 = puVar1 + 1;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0x14;
    } while (iVar4 < param_1[8]);
  }
  return;
}
