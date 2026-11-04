/* FUN_80030d68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030d68  body 0x80030d68..0x80030e9f  size 312 B
 * body sha256 217810a0fa8e2ecbdabe85de3a00116650e37611e9cc6386a4582fba2ba86222
 * provider record sha256 a592ebc0fa0fbf3781e010afee555e22eff2d0ee3889fd1c9082b410b41556a1
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80030d68(int *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  param_1[1] = 0;
  uVar1 = FUN_8002fcd8();
  puVar2 = (undefined4 *)FUN_8002fc78(param_1,0x50);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_8002fcec(param_1);
    *(undefined4 *)(*param_1 + 0x14) = 0x2e;
    *(undefined4 *)(*param_1 + 0x18) = 0;
    (**(code **)*param_1)(param_1);
  }
  iVar4 = 1;
  puVar3 = puVar2 + 1;
  *puVar2 = FUN_8002fd38;
  puVar2[1] = FUN_8002fef4;
  puVar2[2] = FUN_8002ffec;
  puVar2[3] = FUN_8003011c;
  puVar2[4] = FUN_8003025c;
  puVar2[5] = FUN_80030324;
  puVar2[6] = FUN_800303ec;
  puVar2[7] = FUN_800308ec;
  puVar2[8] = FUN_80030a3c;
  puVar2[9] = FUN_80030b8c;
  puVar2[10] = FUN_80030d0c;
  puVar2[0xb] = uVar1;
  do {
    puVar3[0xc] = 0;
    puVar3[0xe] = 0;
    iVar4 = iVar4 + -1;
    puVar3 = puVar3 + -1;
  } while (-1 < iVar4);
  puVar2[0x10] = 0;
  puVar2[0x11] = 0;
  puVar2[0x12] = 0x50;
  param_1[1] = (int)puVar2;
  return;
}
