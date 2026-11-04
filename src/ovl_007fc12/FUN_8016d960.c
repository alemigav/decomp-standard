/* FUN_8016d960
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016d960  body 0x8016d960..0x8016dcdf  size 896 B
 * body sha256 90f87a245f01205fc771bf50ebf9e784f10557170a75e85045f340cf43804700
 * provider record sha256 2f26e830d0f53e5a24e0c32de7d39fc6c8261b7e86fe1d5c68b0f3d87b416ad9
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016d960(int param_1)

{
  byte bVar1;
  short sVar2;
  char cVar6;
  ushort uVar5;
  uint uVar3;
  uint uVar4;
  undefined1 uVar7;
  uint *puVar8;
  int iVar9;
  undefined2 local_38;
  undefined2 local_36;
  short local_34;
  undefined1 auStack_30 [20];
  int local_1c;
  undefined4 local_18;
  int local_14;
  
  puVar8 = (uint *)(*(int *)(param_1 + 0x234) +
                   (uint)(*(byte *)(param_1 + 0x2d9) >> 1) * 0x468 + 0xd38);
  switch(*(undefined1 *)(param_1 + 0x2d8)) {
  default:
    break;
  case 1:
    puVar8[0x4c] = 0x30;
    puVar8[0x4d] = 0x101020;
    *puVar8 = *puVar8 | 0x9280;
    puVar8[0x5e] = puVar8[0x5e] | 0x9200;
    puVar8[0xbc] = puVar8[0xbc] | 0x9200;
    *puVar8 = *puVar8 | 0x80;
    puVar8[0x19] = _DAT_800e1364 + 0x38;
    puVar8[0x4b] = _DAT_800e1364;
    func_0x80049ff8(_DAT_800e1364 + 0x38,puVar8 + 0xe,puVar8 + 2);
    func_0x80049ff8(_DAT_800e1364 + 0x38,puVar8 + 0xca,auStack_30);
    *(short *)(param_1 + 0x2dc) = (short)(local_1c >> 1);
    *(short *)(param_1 + 0x2de) = local_18._2_2_ + 200;
    *(undefined1 *)(param_1 + 0x2d8) = 2;
    *(undefined1 *)(param_1 + 0x2d7) = 0x3c;
    *(short *)(param_1 + 0x2e0) = (short)(local_14 >> 1);
    func_0x80077d18(9,param_1);
    iVar9 = func_0x80040bb4((int)*(short *)(param_1 + 0x2dc) * (int)*(short *)(param_1 + 0x2dc) +
                            (int)*(short *)(param_1 + 0x2e0) * (int)*(short *)(param_1 + 0x2e0));
    uVar7 = 3;
    if (800 < iVar9) goto LAB_8016dcc4;
  case 2:
    cVar6 = *(char *)(param_1 + 0x2d7) + -1;
    *(char *)(param_1 + 0x2d7) = cVar6;
    if (cVar6 == -1) {
      *(undefined1 *)(param_1 + 0x2d8) = 3;
    }
    func_0x80049ff8(_DAT_800e1364 + 0x38,puVar8 + 0xca,auStack_30);
    puVar8[7] = puVar8[7] + (*(short *)(param_1 + 0x2dc) - local_1c);
    puVar8[8] = puVar8[8] + (*(short *)(param_1 + 0x2de) - local_18);
    puVar8[9] = puVar8[9] + (*(short *)(param_1 + 0x2e0) - local_14);
    local_38 = 0;
    local_36 = 0;
    uVar5 = func_0x80033604();
    local_34 = (uVar5 & 0xf) * ((*(byte *)(param_1 + 0x2d7) & 1) * -2 + 1) + -8;
    func_0x80040e58(&local_38,auStack_30);
    func_0x80041fe0(puVar8 + 2,auStack_30);
    if ((*(byte *)(param_1 + 0x2d7) & 3) == 0) {
      uVar3 = func_0x80033604();
      uVar4 = func_0x80033604();
      func_0x80037780((uVar3 & 1) << 0x10 | (uVar4 & 0xff) + 0xc18,(int)*(short *)(param_1 + 0x66),
                      puVar8 + 0xe,0);
      local_38 = 0;
      local_36 = 0xfe0c;
      local_34 = (ushort)(*(byte *)(param_1 + 0x2d9) >> 1) * 500 + -0xfa;
      iVar9 = *(int *)(param_1 + 0x234);
      uVar3 = func_0x80033604();
      func_0x80037780(uVar3 & 1 | 0xc18,(int)*(short *)(param_1 + 0x66),iVar9 + 0x38,&local_38);
    }
    break;
  case 3:
    *puVar8 = *puVar8 | 0x1062;
    sVar2 = *(short *)(param_1 + 0x66);
    *(undefined2 *)((int)puVar8 + 0x2a) = 0xffec;
    *(undefined2 *)((int)puVar8 + 0x11e) = 0;
    *(undefined2 *)(puVar8 + 0xb) = 0;
    *(undefined1 *)((int)puVar8 + 0x111) = 0x1e;
    *(undefined2 *)((int)puVar8 + 0x2e) = 0;
    *(short *)(puVar8 + 10) = sVar2 + 0x800;
    sVar2 = _DAT_800e1196;
    bVar1 = *(byte *)(param_1 + 0x2d9);
    *(undefined2 *)((int)puVar8 + 0x32) = 0xfc00;
    uVar7 = 4;
    *(ushort *)(puVar8 + 0xc) = sVar2 + (~(ushort)bVar1 & 1) * 0x800;
LAB_8016dcc4:
    *(undefined1 *)(param_1 + 0x2d8) = uVar7;
  }
  return;
}
