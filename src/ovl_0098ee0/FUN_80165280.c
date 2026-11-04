/* FUN_80165280
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165280  body 0x80165280..0x801655cf  size 848 B
 * body sha256 916cd421fa0f5a6e8da626d6b53ed2fe8326e950ebb97ef5c7cb65c410393f8f
 * provider record sha256 835a3ac6df95ee56e60b28633e3e7b50aa9c6ec14f7289cd35f700f8f5f461c0
 * callees 12 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165280(uint *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  short local_38 [2];
  short local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  int local_28 [2];
  int local_20;
  
  uVar5 = param_1[0x8d];
  iVar3 = func_0x80032d14((int)*(short *)((int)param_1 + 0x2a),(int)*(short *)((int)param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  cVar4 = func_0x80033144(0x800e1130,param_1);
  if (cVar4 == '\0') {
    local_38[0] = 2000;
    local_34 = 0x10e;
    func_0x80036b2c(param_1 + 0xb,_DAT_800e115c + 0x82,1);
  }
  else {
    local_38[0] = 0x640;
    local_34 = 300;
  }
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 0x7a) = 0xc;
        cVar4 = func_0x80036b84(param_1,0xc,3,0);
        cVar4 = *(char *)((int)param_1 + 6) + cVar4;
        *(char *)((int)param_1 + 6) = cVar4;
        if (*(char *)((int)param_1 + 0x1e9) == '?') {
          *(char *)((int)param_1 + 6) = cVar4 + '\x01';
        }
        func_0x800837d0((int)*(short *)((int)param_1 + 0x66),local_38,local_38);
        local_28[0] = param_1[10] + (int)local_38[0];
        local_20 = param_1[0xc] + (int)local_34;
        func_0x80036a30(&DAT_800e1158,local_28,0xfa);
        cVar4 = *(char *)((int)param_1 + 0x1e9);
        if (cVar4 == '2') {
          local_30 = *(undefined2 *)(uVar5 + 0x11ee);
          local_2e = *(undefined2 *)(uVar5 + 0x11f2);
          local_2c = *(undefined2 *)(uVar5 + 0x11f6);
          func_0x80037780(0x2800,0,0x800e9028,&local_30);
          cVar4 = *(char *)((int)param_1 + 0x1e9);
        }
        if (cVar4 == '-') {
          func_0x80052bd0(4,0);
          func_0x80052c6c(10,0xff,0);
          func_0x80052d10(8,0xff,0x28,10);
          func_0x80052bd0(3,0x2e);
          func_0x80052d10(0x10,200,0x5a,0x2e);
          func_0x80052d10(0x28,100,0x28,0x3e);
          return;
        }
        return;
      }
      if (bVar1 != 3) {
        return;
      }
      func_0x80032ef4(param_1,(iVar3 + 0x60) * 0x10000 >> 0x10,0x30);
      cVar4 = func_0x80036b84(param_1,0xd,3,0);
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar4;
      if (*(char *)((int)param_1 + 0x1e9) == -0x6b) {
        *(undefined1 *)((int)param_1 + 0x1e9) = 0x74;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *param_1 = *param_1 | 10;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  *(undefined1 *)(param_1 + 0x7a) = 2;
  cVar4 = func_0x80036c68(param_1,2,3,0);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar4;
  func_0x800837d0((int)*(short *)((int)param_1 + 0x66),local_38,local_38);
  local_28[0] = param_1[10] + (int)local_38[0];
  local_20 = param_1[0xc] + (int)local_34;
  func_0x80036a30(&DAT_800e1158,local_28,300);
  func_0x80032ef4(param_1,(iVar3 + 0x60) * 0x10000 >> 0x10,0x30);
  sVar2 = *(short *)(param_1 + 0x7d);
  *(short *)(param_1 + 0x7d) = sVar2 + 1;
  if (6 < (short)(sVar2 + 1)) {
    *(undefined1 *)((int)param_1 + 0x1e9) = 9;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  return;
}
