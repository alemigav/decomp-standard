/* FUN_80165920
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80165920  body 0x80165920..0x80165bbf  size 672 B
 * body sha256 f2f9875e61b0062e6a363cef7396771042e8713e313c02e9c4ab819a5ec74b23
 * provider record sha256 2eac889d1fe9e8862322515396f7c9fbc8d063288865b60c1a5b42bb70c3cbc8
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165920(int param_1,uint *param_2)

{
  char cVar4;
  short sVar2;
  ushort uVar3;
  uint uVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  switch(*(undefined1 *)(param_1 + 0x2b5)) {
  case 0:
    *(undefined2 *)(param_2 + 0x47) = 0x1000;
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    *(undefined1 *)((int)param_2 + 0x112) = 1;
    uVar3 = func_0x80033604();
    *(ushort *)((int)param_2 + 0x11e) = (uVar3 & 3) + 1;
    *(undefined1 *)((int)param_2 + 0x111) = 0x1e;
    *param_2 = *param_2 & 0xffffbfff;
  case 1:
    cVar4 = *(char *)((int)param_2 + 0x111) + -1;
    *(char *)((int)param_2 + 0x111) = cVar4;
    if (cVar4 == -1) {
      *(undefined1 *)(param_1 + 0x2b5) = 2;
      *(undefined1 *)((int)param_2 + 0x111) = 0x3c;
    }
    break;
  case 2:
    cVar4 = *(char *)((int)param_2 + 0x111) + -1;
    *(char *)((int)param_2 + 0x111) = cVar4;
    *(short *)(param_2 + 0x49) = *(short *)(param_2 + 0x49) + -0x14;
    if (cVar4 == -1) {
      *(undefined1 *)(param_1 + 0x2b5) = 3;
    }
    break;
  case 3:
    sVar2 = *(short *)(param_2 + 0x49);
    *(ushort *)(param_2 + 0x49) = sVar2 - 0x200U;
    if (-1 < (int)((uint)(ushort)(sVar2 - 0x200U) << 0x10)) break;
    *(undefined1 *)(param_1 + 0x2b5) = 4;
    *param_2 = *param_2 | 0x4000;
  default:
  }
  *(short *)(param_2[0x48] + 0xc) = 0x1000 - *(short *)(param_2 + 0x47);
  *(undefined2 *)(param_2[0x48] + 0x10) = *(undefined2 *)(param_2 + 0x47);
  func_0x80066288(param_1,param_2);
  *(short *)(param_2 + 0x47) = *(short *)(param_2 + 0x47) + *(char *)((int)param_2 + 0x112) * 0x400;
  local_18 = 0x10;
  local_16 = 0x70;
  local_14 = 0;
  if (*(byte *)(param_1 + 0x2b5) < 4) {
    sVar2 = *(short *)((int)param_2 + 0x11e) + -1;
    *(short *)((int)param_2 + 0x11e) = sVar2;
    if (sVar2 == -1) {
      *(char *)((int)param_2 + 0x112) = -*(char *)((int)param_2 + 0x112);
      uVar3 = func_0x80033604();
      *(ushort *)((int)param_2 + 0x11e) = (uVar3 & 3) + 1;
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) + 0xddc | 0x140000,0,param_2 + 0xe,&local_18);
    }
    sVar2 = *(short *)(param_2 + 0x47);
    if (sVar2 < 0) {
      *(undefined1 *)((int)param_2 + 0x112) = 1;
      uVar3 = func_0x80033604();
      *(ushort *)((int)param_2 + 0x11e) = (uVar3 & 3) + 1;
      *(short *)(param_2 + 0x47) =
           *(short *)(param_2 + 0x47) + *(char *)((int)param_2 + 0x112) * 0x400;
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) + 0xddc | 0x140000,0,param_2 + 0xe,&local_18);
      sVar2 = *(short *)(param_2 + 0x47);
    }
    if (0x1000 < sVar2) {
      *(undefined1 *)((int)param_2 + 0x112) = 0xff;
      uVar3 = func_0x80033604();
      *(ushort *)((int)param_2 + 0x11e) = (uVar3 & 3) + 1;
      *(short *)(param_2 + 0x47) =
           *(short *)(param_2 + 0x47) + *(char *)((int)param_2 + 0x112) * 0x400;
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) + 0xddc | 0x140000,0,param_2 + 0xe,&local_18);
    }
  }
  return;
}
