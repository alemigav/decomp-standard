/* FUN_80164000
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164000  body 0x80164000..0x801641f7  size 504 B
 * body sha256 0a374bbd5316a72770014530f131a7e245696b18bad48eaa31716774b56a41f9
 * provider record sha256 97320b3adbf4f480aebd08d59e4054f31049347b3e4a6b2b24793e51787b0fe5
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164000(uint *param_1)

{
  byte bVar1;
  char cVar3;
  int iVar2;
  uint uVar4;
  undefined2 local_18;
  short local_16;
  undefined2 local_14;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  uVar4 = param_1[0x8d];
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)(param_1 + 0xb2) = 0x32;
        param_1[1] = 0x1010000;
        *param_1 = *param_1 & 0xfffffffb;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    *param_1 = *param_1 | 4;
  }
  cVar3 = func_0x80036c68(param_1,0xc,0xf,0);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar3;
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,8);
  iVar2 = FUN_80161e10(param_1,0xc,0x2f,0x32,0x226);
  if (iVar2 != 0) {
    func_0x80077d18(2,param_1);
    _DAT_800e1134 = 0x2000000;
    cVar3 = func_0x80033144(param_1,0x800e1130);
    cVar3 = DAT_800e1135 + cVar3;
    _DAT_800e1135 = CONCAT12(cVar3,DAT_800e1134_1._1_2_);
    local_18 = *(undefined2 *)(uVar4 + 0x11ee);
    local_14 = *(undefined2 *)(uVar4 + 0x11f6);
    local_16 = *(short *)(uVar4 + 0x11f2);
    if ((int)*(short *)(uVar4 + 0x11f2) < *(short *)((int)param_1 + 0x25e) + -3000) {
      local_16 = *(short *)((int)param_1 + 0x25e) + -3000;
    }
    func_0x80037780(0x2400,0,0x800e9028,&local_18);
    local_16 = local_16 + 100;
    func_0x80037780(0x2b00,0,0x800e9028,&local_18);
    func_0x80052bd0(3,0);
    func_0x80052c6c(8,0xff,0);
    func_0x80052d10(4,0xff,0x28,8);
    FUN_80162114(0x28);
  }
  return;
}
