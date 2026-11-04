/* FUN_800897d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800897d4  body 0x800897d4..0x80089a97  size 708 B
 * body sha256 19eac4cf317907410f4fc2e18beb5949aee0aa04860c3c9a6654995ba74c2dee
 * provider record sha256 162bd9af4675b6fd5befee6414daee382777103206329dcc8c45fc267f37480c
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800897d4(uint *param_1,int param_2)

{
  uint *puVar1;
  short sVar4;
  int iVar2;
  uint uVar3;
  undefined1 auStack_a0 [32];
  undefined2 local_80;
  undefined2 local_7e;
  undefined2 local_7c;
  undefined1 auStack_78 [96];
  
  puVar1 = DAT_800df938;
  sVar4 = *(short *)((int)param_1 + 0x11e);
  if (sVar4 == 0) {
    local_7e = *(undefined2 *)(param_1 + 10);
    local_7c = 0;
    local_80 = 0;
    FUN_80040e58(&local_80,auStack_a0);
    local_80 = *(undefined2 *)(param_1 + 0xb);
    local_7e = *(undefined2 *)((int)param_1 + 0x2a);
    FUN_8004276c(auStack_a0,&local_80,param_1 + 10);
    *(undefined2 *)((int)param_1 + 0x11e) = 3;
    *(undefined1 *)((int)param_1 + 0x112) = 0xf;
    sVar4 = *(short *)((int)param_1 + 0x11e);
  }
  if (1 < sVar4) {
    iVar2 = FUN_80069f1c(param_1 + 0x13,100,0x2000,1);
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + (int)*(short *)(param_1 + 10);
    sVar4 = *(short *)((int)param_1 + 0x2a) + (short)*(char *)((int)param_1 + 0x111);
    *(short *)((int)param_1 + 0x2a) = sVar4;
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + (int)sVar4;
    *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + (int)*(short *)(param_1 + 0xb);
    if (iVar2 < *(int *)(param_2 + 0x18)) {
      *(short *)((int)param_1 + 0x11e) = *(short *)((int)param_1 + 0x11e) + -1;
      *(int *)(param_2 + 0x18) = iVar2;
      *(short *)((int)param_1 + 0x2a) = -*(short *)((int)param_1 + 0x2a) >> 2;
      *(short *)(param_1 + 10) = *(short *)(param_1 + 10) >> 2;
      *(short *)(param_1 + 0xb) = *(short *)(param_1 + 0xb) >> 2;
      uVar3 = FUN_80033604();
      FUN_80037780((*puVar1 >> 0x13 & 0x18) << 0x10 | 2000,(uVar3 & 0xff) << 4,param_1 + 0xe,0);
      if ((*param_1 & 0x10) != 0) {
        *param_1 = *param_1 | 0x2000;
        *(undefined2 *)(param_1 + 0x49) = 7000;
        *(undefined2 *)(param_1 + 0x4a) = 7000;
        *(undefined2 *)((int)param_1 + 0x126) = 0;
        *(undefined2 *)((int)param_1 + 0x11e) = 1;
      }
      if (*(short *)((int)param_1 + 0x11e) == 1) {
        *(int *)(param_2 + 0x18) = iVar2;
        *param_1 = *param_1 & 0xfffffffe;
      }
    }
    iVar2 = FUN_800667d4(param_1 + 0x13,100,1 << (-((int)param_1[0x14] / 0x708) & 0x1fU),0x2000);
    if (iVar2 != 0) {
      *(short *)(param_1 + 10) = *(short *)(param_1 + 10) >> 2;
      *(short *)(param_1 + 0xb) = *(short *)(param_1 + 0xb) >> 2;
      *(short *)(param_1 + 10) = -*(short *)(param_1 + 10);
      *(short *)(param_1 + 0xb) = -*(short *)(param_1 + 0xb);
    }
  }
  if (-1 < *(char *)((int)param_1 + 0x112)) {
    local_80 = *(undefined2 *)((int)param_1 + 0x2e);
    local_7e = *(undefined2 *)(param_1 + 0xc);
    local_7c = *(undefined2 *)((int)param_1 + 0x32);
    FUN_80040e58(&local_80,auStack_78);
    FUN_80089c3c(param_1 + 0xe,auStack_78,param_1 + 0xe,
                 *(char *)((int)param_1 + 0x112) * -0x100 + 0x1000);
    *(char *)((int)param_1 + 0x112) = *(char *)((int)param_1 + 0x112) + -1;
  }
  return;
}
