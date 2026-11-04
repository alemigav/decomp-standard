/* FUN_8016cec4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016cec4  body 0x8016cec4..0x8016d347  size 1156 B
 * body sha256 c2be694e2b1e4a014bf817f539b689d37887d9edd4449f7d239f2fcdd3f5a54a
 * provider record sha256 706e2b2f8d45774957258e9c0f356f1c4a8d02bbc11e8691be4345070920eca9
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016cec4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  ushort uVar3;
  char cVar4;
  byte bVar5;
  uint uVar2;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined4 local_6c;
  undefined1 auStack_68 [24];
  int local_50;
  short local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  short local_38 [2];
  short local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  
  func_0x80082200(&local_70,0,0x30);
  local_6c = 0x7e;
  if ((*(ushort *)((int)param_1 + 0x2b6) & 1) == 0) {
    return;
  }
  switch(*(undefined1 *)((int)param_1 + 0x2b5)) {
  case 0:
    *(undefined1 *)((int)param_1 + 0x2b9) = 0;
    *(undefined1 *)((int)param_1 + 0x2ba) = 7;
    *(undefined1 *)(param_1 + 0xae) = *(undefined1 *)(param_1 + 0xad);
    param_1[0x73] = *(uint *)(param_1[0x8d] + 0x1c4);
    uVar2 = *(uint *)(param_1[0x8d] + 0x1cc);
    *(undefined1 *)((int)param_1 + 0x2b5) = 1;
    *(undefined2 *)(param_1 + 0xaf) = *(undefined2 *)((int)param_1 + 0x66);
    param_1[0x75] = uVar2;
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 699) = (bVar5 & 0x1f) + 10;
    func_0x800339dc(param_1 + 0xb0,0,0x2bc01f4,0,param_1 + 0x73);
  case 1:
    local_70 = *(undefined1 *)(param_1 + 0xae);
    local_6f = *(undefined1 *)((int)param_1 + 0x2b9);
    local_6e = *(undefined1 *)((int)param_1 + 0x2ba);
    func_0x8008a348(&local_70,param_1[0x69],param_1[0x86],0x200);
    *(undefined1 *)(param_1 + 0xae) = local_70;
    *(undefined1 *)((int)param_1 + 0x2b9) = local_6f;
    *(undefined1 *)((int)param_1 + 0x2ba) = local_6e;
    local_40 = 0;
    local_3e = *(undefined2 *)(param_1 + 0xaf);
    local_3c = 0;
    func_0x80040e58(&local_40,&local_30);
    uVar3 = func_0x80033604();
    local_40 = (uVar3 & 7) + 10;
    local_3e = 0;
    func_0x8004276c(&local_30,&local_40,local_38);
    param_1[0x73] = param_1[0x73] + (int)local_38[0];
    cVar4 = *(char *)((int)param_1 + 699) + -1;
    *(char *)((int)param_1 + 699) = cVar4;
    param_1[0x75] = param_1[0x75] + (int)local_34;
    if (cVar4 == -1) {
      *(undefined1 *)((int)param_1 + 0x2b5) = 2;
    }
    break;
  case 2:
    *(undefined1 *)(param_1 + 0xae) = 1;
    *(undefined1 *)((int)param_1 + 0x2ba) = 7;
    *(undefined1 *)((int)param_1 + 0x2b9) = 0;
    *(undefined1 *)((int)param_1 + 0x2b5) = 3;
  case 3:
    local_70 = *(undefined1 *)(param_1 + 0xae);
    local_6f = *(undefined1 *)((int)param_1 + 0x2b9);
    local_6e = *(undefined1 *)((int)param_1 + 0x2ba);
    cVar4 = func_0x8008a348(&local_70,param_2,param_3,0x200);
    *(char *)((int)param_1 + 0x2b5) = *(char *)((int)param_1 + 0x2b5) + cVar4;
    *(undefined1 *)(param_1 + 0xae) = local_70;
    *(undefined1 *)((int)param_1 + 0x2b9) = local_6f;
    *(undefined1 *)((int)param_1 + 0x2ba) = local_6e;
    local_40 = 0;
    local_3e = *(undefined2 *)(param_1 + 0xaf);
    local_3c = 0;
    func_0x80040e58(&local_40,&local_30);
    local_40 = 0x1e;
    local_3e = 0;
    func_0x8004276c(&local_30,&local_40,local_38);
    param_1[0x73] = param_1[0x73] + (int)local_38[0];
    param_1[0x75] = param_1[0x75] + (int)local_34;
    break;
  case 4:
    *(uint *)(param_1[0x8d] + 0x178) = *(uint *)(param_1[0x8d] + 0x178) | 0x40;
    *(undefined1 *)((int)param_1 + 0x2b5) = 5;
    *(undefined1 *)(param_1 + 0xae) = 0x16;
    *(undefined1 *)((int)param_1 + 0x2b9) = 0;
    *(undefined1 *)((int)param_1 + 0x2ba) = 7;
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 699) = (bVar5 & 0x1f) + 10;
    func_0x800341dc(param_1[0xb0],_DAT_800c76b0);
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
LAB_8016d22c:
      *(undefined1 *)((int)param_1 + 0x2b5) = 8;
      return;
    }
  case 5:
    local_70 = *(undefined1 *)(param_1 + 0xae);
    local_6f = *(undefined1 *)((int)param_1 + 0x2b9);
    local_6e = *(undefined1 *)((int)param_1 + 0x2ba);
    cVar4 = func_0x8008a348(&local_70,param_2,param_3,0x200);
    *(char *)((int)param_1 + 0x2b5) = *(char *)((int)param_1 + 0x2b5) + cVar4;
    *(undefined1 *)(param_1 + 0xae) = local_70;
    *(undefined1 *)((int)param_1 + 0x2b9) = local_6f;
    *(undefined1 *)((int)param_1 + 0x2ba) = local_6e;
    break;
  case 6:
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 699) = (bVar5 & 0x1f) + 0x3c;
    *(undefined1 *)((int)param_1 + 0x2b5) = 7;
    uVar2 = func_0x80033604();
    if ((uVar2 & 0xf) == 0) goto LAB_8016d22c;
    goto LAB_8016d238;
  case 7:
LAB_8016d238:
    local_70 = *(undefined1 *)(param_1 + 0xae);
    local_6f = 0;
    local_6e = 0;
    func_0x8008a348(&local_70,param_2,param_3,0x200);
    cVar4 = *(char *)((int)param_1 + 699) + -1;
    *(char *)((int)param_1 + 699) = cVar4;
    if (cVar4 == -1) {
      *(undefined1 *)((int)param_1 + 0x2b5) = 5;
    }
    break;
  case 8:
    local_70 = *(undefined1 *)(param_1 + 0xae);
    local_6f = 0;
    local_6e = 0;
    func_0x8008a348(&local_70,param_2,param_3,0x200);
  default:
    break;
  }
  if (*(byte *)((int)param_1 + 0x2b5) < 4) {
    uVar1 = *(undefined2 *)((int)param_1 + 0x66);
    *(undefined2 *)((int)param_1 + 0x66) = *(undefined2 *)(param_1 + 0xaf);
    func_0x80040e58(param_1 + 0x19,param_1 + 5);
    *(undefined2 *)((int)param_1 + 0x66) = uVar1;
    func_0x800424ec(param_1 + 5,auStack_68,&local_30);
    param_1[0x6e] = local_30;
    param_1[0x6f] = local_2c;
    param_1[0x70] = local_28;
    param_1[0x71] = local_24;
    param_1[0x72] = local_20;
    param_1[0x74] = local_50 + *(short *)((int)param_1 + 0x2ce);
  }
  func_0x80033a60(param_1[0xb0],(int)*(short *)((int)param_1 + 0x25e),
                  (int)*(short *)(param_1 + 0xaf),(*param_1 & 0x400) >> 9);
  return;
}
