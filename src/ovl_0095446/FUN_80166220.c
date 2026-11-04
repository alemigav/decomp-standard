/* FUN_80166220
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80166220  body 0x80166220..0x801669bb  size 1948 B
 * body sha256 7b4ea2578d1fdf466f8f361d7e52d357ba567acb418065e98bee1dda9718c77f
 * provider record sha256 0c8a482924a47e8a0ee3d6dc4b75379295c89f0aaf260fe06927878c3798b29f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166220(int param_1,uint *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  ushort uVar5;
  uint uVar4;
  undefined1 uVar6;
  uint *puVar7;
  short local_28;
  short local_26;
  short local_24;
  
  if ((*(ushort *)(param_1 + 0x2ba) & 1) != 0) {
    *param_2 = *param_2 | 0x40;
    *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) & 0xfffe | 2;
    *(undefined1 *)(param_2 + 0x4c) = 0;
  }
  if ((*(ushort *)(param_1 + 0x2ba) & 2) == 0) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x234);
  switch(*(undefined1 *)(param_2 + 0x4c)) {
  case 0:
    *(undefined1 *)(param_2 + 0x4c) = 1;
    *(undefined2 *)(param_2 + 0x47) = 100;
    *(undefined1 *)((int)param_2 + 0x112) = 4;
    *(undefined1 *)((int)param_2 + 0x111) = 0;
    uVar5 = func_0x80033604();
    local_28 = *(short *)((int)param_2 + 0x1e) - ((uVar5 & 0x7f) - 0x40);
    uVar5 = func_0x80033604();
    local_26 = *(short *)((int)param_2 + 0x22) - ((uVar5 & 0x7f) - 0x40);
    uVar5 = func_0x80033604();
    local_24 = *(short *)((int)param_2 + 0x26) - ((uVar5 & 0x7f) - 0x40);
    func_0x80037780(0x91f40,(int)((*(ushort *)(param_1 + 0x66) - 0x400) * 0x10000) >> 0x10,
                    iVar2 + 0x1b0,&local_28);
  case 1:
    uVar4 = *(byte *)((int)param_2 + 0x111) + 1;
    *(char *)((int)param_2 + 0x111) = (char)uVar4;
    if (((int)(uVar4 * 0x1000000) >> 0x18 < 0x5a) && ((uVar4 & 3) == 0)) {
      uVar5 = func_0x80033604();
      local_28 = *(short *)((int)param_2 + 0x1e) - ((uVar5 & 0x7f) - 0x40);
      uVar5 = func_0x80033604();
      local_26 = *(short *)((int)param_2 + 0x22) - ((uVar5 & 0x7f) - 0x40);
      uVar5 = func_0x80033604();
      local_24 = *(short *)((int)param_2 + 0x26) - ((uVar5 & 0x7f) - 0x40);
      uVar4 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) * 8 + 0x1000 | 0x80000,
                      (int)((*(ushort *)(param_1 + 0x66) - 0x400) * 0x10000) >> 0x10,iVar2 + 0x1b0,
                      &local_28);
      uVar5 = func_0x80033604();
      local_28 = 0x40 - (uVar5 & 0x7f);
      uVar5 = func_0x80033604();
      local_26 = 0x40 - (uVar5 & 0x7f);
      uVar5 = func_0x80033604();
      local_24 = 0x40 - (uVar5 & 0x7f);
      uVar4 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) * 8 + 0x1000 | 0x80000,0,param_2 + 0xe,&local_28);
    }
    sVar1 = *(short *)(param_2 + 0x47);
    *(short *)(param_2 + 0x47) = sVar1 + 0x1e;
    uVar3 = param_2[0x14] + (int)(short)(sVar1 + 0x1e);
    param_2[0x14] = uVar3;
    uVar4 = (int)*(short *)(param_1 + 0x25e) - 200;
    if ((int)uVar4 < (int)uVar3) {
      param_2[0x14] = uVar4;
      *(char *)((int)param_2 + 0x112) = *(char *)((int)param_2 + 0x112) + -1;
      *(short *)(param_2 + 0x47) = -*(short *)(param_2 + 0x47) >> 1;
      uVar5 = func_0x80033604();
      local_28 = 0x40 - (uVar5 & 0x7f);
      uVar5 = func_0x80033604();
      local_26 = 0x40 - (uVar5 & 0x7f);
      uVar5 = func_0x80033604();
      local_24 = 0x40 - (uVar5 & 0x7f);
      uVar4 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) << 3 | 0x81000,0,param_2 + 0xe,&local_28);
      if (*(char *)((int)param_2 + 0x112) == '\0') {
        *(undefined1 *)(param_2 + 0x4c) = 2;
      }
    }
    break;
  case 2:
    *(undefined1 *)(param_2 + 0x4c) = 3;
    iVar2 = 4;
    puVar7 = param_2 + 0x178;
    do {
      iVar2 = iVar2 + -1;
      puVar7[-0x5e] = puVar7[-0x5e] | 0x2000;
      *(undefined2 *)(puVar7 + -0x15) = 0x1000;
      *(undefined2 *)((int)puVar7 + -0x52) = 0x1000;
      *(undefined2 *)(puVar7 + -0x14) = 0x1000;
      puVar7 = puVar7 + -0x5e;
    } while (iVar2 != 0);
    *(undefined2 *)(param_2 + 0x47) = 0;
  case 3:
    iVar2 = 4;
    *(short *)(param_2 + 0x47) = *(short *)(param_2 + 0x47) + 1;
    param_2[0x14] = param_2[0x14] + 2;
    puVar7 = param_2 + 0x178;
    do {
      iVar2 = iVar2 + -1;
      puVar7[-0x5e] = puVar7[-0x5e] | 0x2000;
      *(short *)(puVar7 + -0x15) = *(short *)(puVar7 + -0x15) + 0x14;
      *(short *)((int)puVar7 + -0x52) = *(short *)((int)puVar7 + -0x52) + -0x28;
      *(short *)(puVar7 + -0x14) = *(short *)(puVar7 + -0x14) + 0x14;
      puVar7[-0x46] = puVar7[-0x46] - 0x10001;
      puVar7 = puVar7 + -0x5e;
    } while (iVar2 != 0);
    if ((param_2[0x47] & 0x10000) == 0) {
      uVar5 = func_0x80033604();
      local_28 = 0x80 - (uVar5 & 0xff);
      uVar5 = func_0x80033604();
      local_26 = 0x80 - (uVar5 & 0xff);
      uVar5 = func_0x80033604();
      local_24 = 0x80 - (uVar5 & 0xff);
      uVar4 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) * 4 + 0x448 | 0x80000,0,param_2 + (uVar3 & 1) * 0x5e + 0x6c,
                      &local_28);
    }
    if (*(short *)((int)param_2 + 0x126) < 0x28) {
      *(undefined1 *)(param_2 + 0x4c) = 4;
    }
    break;
  case 4:
    iVar2 = 4;
    puVar7 = param_2 + 0x178;
    do {
      func_0x8004a5b4(puVar7 + -0x5d,1);
      iVar2 = iVar2 + -1;
      puVar7[-0x5d] = puVar7[-0x5d] | 2;
      puVar7[-0x46] = puVar7[-0x46] - 0x2000;
      puVar7 = puVar7 + -0x5e;
    } while (iVar2 != 0);
    *(undefined1 *)(param_2 + 0x4c) = 5;
  case 5:
    iVar2 = 4;
    if (*(char *)((int)param_2 + 99) != '\0') {
      puVar7 = param_2 + 0x178;
      do {
        iVar2 = iVar2 + -1;
        puVar7[-0x46] = puVar7[-0x46] - 0x10001;
        puVar7 = puVar7 + -0x5e;
      } while (iVar2 != 0);
    }
    iVar2 = 4;
    if ((param_2[0x18] & 0xff00) == 0) {
      uVar6 = 6;
LAB_80166994:
      *(undefined1 *)(param_2 + 0x4c) = uVar6;
    }
    else {
      puVar7 = param_2 + 0x178;
      do {
        iVar2 = iVar2 + -1;
        puVar7[-0x46] = puVar7[-0x46] - 0x100;
        puVar7 = puVar7 + -0x5e;
      } while (iVar2 != 0);
    }
    break;
  case 6:
    iVar2 = 4;
    puVar7 = param_2 + 0x178;
    do {
      puVar7[-0x5d] = puVar7[-0x5d] & 0xfffffffd;
      uVar4 = puVar7[-0x5e];
      puVar7[-0x5e] = uVar4 & 0xffffddbf | 0x400;
      if (iVar2 != 1) {
        puVar7[-0x5e] = uVar4 & 0xffffddbf | 0xc00;
      }
      iVar2 = iVar2 + -1;
      puVar7[-0x46] = 0x508050;
      *(undefined2 *)(puVar7 + -0x15) = 0x1000;
      *(undefined2 *)((int)puVar7 + -0x52) = 0;
      *(undefined2 *)(puVar7 + -0x14) = 0x1000;
      puVar7 = puVar7 + -0x5e;
    } while (iVar2 != 0);
    *(undefined1 *)(param_2 + 0x4c) = 7;
    *(undefined2 *)(param_2 + 0x47) = 0;
  case 7:
    if (*(short *)(param_2 + 0x47) == 0xff) {
      *(undefined1 *)(param_2 + 0x4c) = 8;
      *(undefined1 *)((int)param_2 + 0x112) = 4;
      *(undefined2 *)(param_2 + 0x47) = 0;
      *(undefined1 *)((int)param_2 + 0x111) = 1;
      *(undefined2 *)((int)param_2 + 0x11e) = 0;
    }
    break;
  case 8:
    sVar1 = *(short *)(param_2 + 0x47);
    *(ushort *)(param_2 + 0x47) = sVar1 + 1U;
    if ((sVar1 + 1U & 3) == 0) {
      uVar5 = func_0x80033604();
      local_28 = 0x80 - (uVar5 & 0xff);
      uVar5 = func_0x80033604();
      local_26 = 0x80 - (uVar5 & 0xff);
      uVar5 = func_0x80033604();
      local_24 = 0x80 - (uVar5 & 0xff);
      uVar4 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) * 8 + 0xc18 | 0x80000,
                      (int)((*(ushort *)(param_1 + 0x66) - 0x400) * 0x10000) >> 0x10,param_2 + 0xe,
                      &local_28);
      uVar5 = func_0x80033604();
      local_28 = 0x80 - (uVar5 & 0xff);
      uVar5 = func_0x80033604();
      local_26 = 0x80 - (uVar5 & 0xff);
      uVar5 = func_0x80033604();
      local_24 = 0x80 - (uVar5 & 0xff);
      uVar4 = func_0x80033604();
      func_0x80037780((uVar4 & 0xff) * 8 + 0x830 | 0x110000,
                      (int)((*(ushort *)(param_1 + 0x66) - 0x400) * 0x10000) >> 0x10,param_2 + 0xe,
                      &local_28);
    }
    if ((0x3c < *(short *)(param_2 + 0x47)) && (*(char *)((int)param_2 + 99) != -0x80)) {
      iVar2 = 4;
      puVar7 = param_2 + 0x18;
      do {
        iVar2 = iVar2 + -1;
        *puVar7 = *puVar7 + 0x80008;
        puVar7 = puVar7 + 0x5e;
      } while (iVar2 != 0);
    }
    puVar7 = param_2 + *(char *)((int)param_2 + 0x112) * 0x5e;
    *(short *)((int)puVar7 + -0x52) =
         *(short *)((int)puVar7 + -0x52) + 0xf0 + *(char *)((int)param_2 + 0x111) * 0x78;
    *(char *)((int)param_2 + 0x111) = -*(char *)((int)param_2 + 0x111);
    if (*(short *)((int)puVar7 + -0x52) < 0x1001) {
      return;
    }
    *(undefined2 *)((int)puVar7 + -0x52) = 0x1000;
    puVar7[-0x5e] = puVar7[-0x5e] & 0xfffffbff;
    *puVar7 = *puVar7 & 0xfffff7ff;
    *(char *)((int)param_2 + 0x112) = *(char *)((int)param_2 + 0x112) + -1;
    *(undefined1 *)(param_1 + 0x207) = 0;
    uVar6 = 9;
    if (*(char *)((int)param_2 + 0x112) != '\0') {
      return;
    }
    goto LAB_80166994;
  default:
    break;
  }
  return;
}
