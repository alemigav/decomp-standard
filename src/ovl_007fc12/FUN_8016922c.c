/* FUN_8016922c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016922c  body 0x8016922c..0x8016964b  size 1056 B
 * body sha256 8ad8f3f3faff2646186e7e422e811c78b2b9c974380dd0a252da9c9ec16fab29
 * provider record sha256 b53cbfbaae3d2f75f7717a711a8550666b795ab72efbdd22f04d7faaa92c5991
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016922c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  undefined2 local_70;
  undefined2 local_6e;
  short local_6c;
  undefined1 auStack_68 [32];
  undefined1 auStack_48 [48];
  
  local_70 = 0;
  local_6e = 0;
  local_6c = 0;
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
        if (iVar3 == 0) {
          local_6c = -(*(short *)(param_1 + 0x7d) * (short)*(char *)((int)param_1 + 0x207)) *
                     *(short *)((int)param_1 + 0x1f6);
          uVar6 = param_1[0x8d];
          func_0x80040e58(&local_70,auStack_68);
          func_0x80041fe0(uVar6 + 8,auStack_68);
          func_0x800416bc(auStack_68,auStack_48);
          func_0x80040cf4(auStack_48,uVar6 + 0x180);
          sVar2 = *(short *)(param_1 + 0x7d);
          *(short *)(param_1 + 0x7d) = sVar2 + -1;
          if ((short)(sVar2 + -1) == -1) {
            *(undefined1 *)((int)param_1 + 6) = 3;
            return;
          }
          return;
        }
      }
      else {
        if (bVar1 != 3) {
          return;
        }
        iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
        if (iVar3 == 0) {
          return;
        }
      }
      goto LAB_801695cc;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined2 *)((int)param_1 + 0x1f6) = 1;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    if ((param_1[0x9b] & 0x200000) != 0) {
      *(undefined2 *)((int)param_1 + 0x1f6) = 0xffff;
    }
    local_6e = 300;
    func_0x80037780(0x17d0,(int)*(short *)((int)param_1 + 0x66),param_1[0x8d] + 0xbf8,&local_70);
    *(undefined1 *)((int)param_1 + 0x1ea) = 0xf;
    if ((param_1[0xb1] & 0xff000000) == 0x1000000) {
      param_1[0xb2] = param_1[0xb1];
    }
    if (*(short *)((int)param_1 + 0x1f2) < 0) {
      uVar5 = param_1[0x8d];
      *(undefined2 *)((int)param_1 + 0x1f2) = 0;
      *(undefined1 *)((int)param_1 + 0x206) = 1;
      uVar6 = func_0x80033604();
      func_0x80037780(0x31f40,(uVar6 & 0xff) << 4,uVar5 + 0xbf8,&local_70);
      *(undefined1 *)((int)param_1 + 0x1ea) = 0xf;
    }
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      func_0x80077d18(0xc,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
    cVar4 = *(char *)((int)param_1 + 5);
    if (((cVar4 == '\n') && ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0)) &&
       (*(byte *)((int)param_1 + 0x26e) < 3)) {
      FUN_80167910(param_1);
      *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x800;
      cVar4 = *(char *)((int)param_1 + 5);
    }
    *(undefined1 *)((int)param_1 + 0x207) = 0x18;
    if (cVar4 == '\x10') {
      if (((*(ushort *)((int)param_1 + 0x1aa) & 0x80) == 0) && (8 < *(byte *)((int)param_1 + 0x2d6))
         ) {
        FUN_80167910(param_1);
        *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x800;
      }
      *(undefined1 *)((int)param_1 + 0x207) = 2;
      *(char *)((int)param_1 + 0x2d6) = *(char *)((int)param_1 + 0x2d6) + '\x01';
    }
    cVar4 = *(char *)((int)param_1 + 5);
    if ((cVar4 == '\x0f') || (cVar4 == '\x12')) {
      *(undefined1 *)((int)param_1 + 0x207) = 2;
      cVar4 = *(char *)((int)param_1 + 5);
    }
    if ((cVar4 == '\v') && (*(byte *)((int)param_1 + 0x26e) < 3)) {
      FUN_80167abc(param_1);
    }
    if (*(char *)((int)param_1 + 5) == '\x0e') {
      FUN_80167c88(param_1);
    }
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar3 == 0) {
    local_6c = *(short *)(param_1 + 0x7d) * (short)*(char *)((int)param_1 + 0x207) * -8 *
               *(short *)((int)param_1 + 0x1f6);
    uVar6 = param_1[0x8d];
    func_0x80040e58(&local_70,auStack_68);
    func_0x80041fe0(uVar6 + 8,auStack_68);
    func_0x800416bc(auStack_68,auStack_48);
    func_0x80040cf4(auStack_48,uVar6 + 0x180);
    sVar2 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar2 + 1;
    if (sVar2 < 3) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 0x7d) = 0x10;
    return;
  }
LAB_801695cc:
  *(undefined2 *)((int)param_1 + 0x136) = 500;
  *(undefined2 *)(param_1 + 0x4e) = 500;
  *(undefined2 *)(param_1 + 0x4b) = 500;
  *(undefined2 *)((int)param_1 + 0x12e) = 500;
  *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
  *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
  *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xffed;
  *param_1 = *param_1 | 0xc000000;
  param_1[1] = param_1[0xb2];
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xdfff;
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  return;
}
