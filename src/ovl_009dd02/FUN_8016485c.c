/* FUN_8016485c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x8016485c  body 0x8016485c..0x80164b97  size 828 B
 * body sha256 5ac317969f3812614d52a7c78b255034c3b097cc142e2bdb0f49408fdc1f4cfb
 * provider record sha256 d2dcf1c9b985ea93ea5e9530cf57cb8d459d9254a1b941a2e49ad22342e972d8
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016485c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  
  bVar1 = *(byte *)((int)param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        if (((_DAT_800e1128 & 0x20) != 0) && (*(char *)((int)param_1 + 0x2cd) == '\0')) {
          *(undefined1 *)((int)param_1 + 5) = 6;
          *(undefined2 *)((int)param_1 + 6) = 0x200;
          func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
          FUN_80163dd8(param_1,param_2,param_3);
          _DAT_800e10ec = _DAT_800e10ec | 0x4000100;
          DAT_800e1134 = 6;
          DAT_800e1135 = 2;
          DAT_800e1136 = 0;
          DAT_800e1137 = 0;
          return;
        }
        *(undefined1 *)((int)param_1 + 7) = 3;
        *(undefined1 *)((int)param_1 + 0x206) = 3;
        *(undefined1 *)((int)param_1 + 0x207) = 1;
        func_0x80077d18(3,param_1);
      }
      else if (bVar1 != 3) goto LAB_80164b04;
      cVar2 = *(char *)((int)param_1 + 0x207);
      *(char *)((int)param_1 + 0x207) = cVar2 + -1;
      if (cVar2 == '\x01') {
        local_28 = 200;
        if (*(char *)((int)param_1 + 0x2cd) != '\0') {
          local_28 = 0xff38;
        }
        local_26 = 0xfe3e;
        local_24 = 0;
        func_0x80037780(0x1d030c00,
                        (int)(((uint)*(ushort *)((int)param_1 + 0x66) +
                              (uint)*(byte *)((int)param_1 + 0x2cd) * 0x800) * 0x10000) >> 0x10,
                        param_1[0x8d] + 0x1060,&local_28);
        cVar2 = *(char *)((int)param_1 + 0x206);
        *(undefined1 *)((int)param_1 + 0x207) = 4;
        *(char *)((int)param_1 + 0x206) = cVar2 + -1;
        if (cVar2 == '\x01') {
          *(undefined1 *)((int)param_1 + 7) = 1;
          *(undefined2 *)((int)param_1 + 0x1f6) = 0x19;
          iVar5 = func_0x80059e00(0x14,0);
          if (iVar5 == 2) {
            _DAT_800e1130 = _DAT_800e1130 & 0xffffffbd;
            FUN_80166960(&DAT_800e1130);
            *(undefined2 *)((int)param_1 + 0x136) = 300;
            *(undefined2 *)(param_1 + 0x4e) = 300;
            *(undefined2 *)((int)param_1 + 6) = 0x200;
            *param_1 = *param_1 & 0xfffffffd | 4;
          }
          else {
            DAT_800e1136 = 2;
            DAT_800e1137 = 0;
            if (iVar5 != 0) {
              _DAT_800e1128 = _DAT_800e1128 | 0x20;
            }
          }
        }
      }
      goto LAB_80164b04;
    }
    if (bVar1 != 0) goto LAB_80164b04;
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined1 *)((int)param_1 + 0x2c1) = 3;
    *(undefined1 *)((int)param_1 + 0x2c3) = 3;
    param_1[0x7a] = ((uint)*(byte *)((int)param_1 + 0x2cd) * 0xd + 9) * 0x1000000 + 0x3f00;
  }
  sVar3 = *(short *)((int)param_1 + 0x1f6);
  *(short *)((int)param_1 + 0x1f6) = sVar3 + -1;
  if (sVar3 == 1) {
    *(undefined1 *)((int)param_1 + 7) = 2;
    *(char *)(param_1 + 0xb7) = *(char *)(param_1 + 0xb7) + -1;
  }
LAB_80164b04:
  iVar5 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar5 != 0) {
    *(undefined1 *)((int)param_1 + 0x1ea) = 0x3f;
  }
  iVar5 = func_0x800331b8();
  uVar4 = *(ushort *)(param_1 + 0x7d);
  *(short *)(param_1 + 0x7d) = (short)((uint)uVar4 - iVar5);
  if ((((int)(((uint)uVar4 - iVar5) * 0x10000) < 0) && (-1 < _DAT_800e1322)) ||
     ((param_1[0xb7] & 0x7f000000) == 0)) {
    *(undefined2 *)((int)param_1 + 6) = 0x200;
    DAT_800e1135 = 2;
    DAT_800e1136 = 0;
    DAT_800e1137 = 0;
    *(undefined1 *)(param_1 + 0xb7) = 0;
  }
  return;
}
