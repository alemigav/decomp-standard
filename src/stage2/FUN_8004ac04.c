/* FUN_8004ac04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ac04  body 0x8004ac04..0x8004afbb  size 952 B
 * body sha256 fe9ed33585c7dbd8af4e4c4e4139909bf106ec392e71c32fa79dfc9361ed94f3
 * provider record sha256 c07a75a9eada1202e6efdf9025325ee2ed69fd9b563a0d76a5c67e239d4ecb09
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004ac04(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  short sVar2;
  uint uVar3;
  
  if ((DAT_8010b294 & 0x80) != 0) {
    return 0xffffffff;
  }
  DAT_8010b294 = 0x80;
  DAT_8010b295 = 0;
  DAT_800e110c = DAT_800e110c | 0x40;
  DAT_8010b2b4 = DAT_800e1110;
  uVar3 = param_2 & 0x300;
  if (uVar3 == 0x200) {
    DAT_8010b2ae = 0xba;
    DAT_8010b2b0 = 0x403;
    if ((DAT_800e10ec & 0x40) == 0) {
      uVar3 = (uint)*(ushort *)(&DAT_800fc818 + param_3 * 2);
      puVar1 = &UNK_800fb530;
    }
    else {
      DAT_8010b2b0 = 0x4403;
      uVar3 = (uint)*(ushort *)(&DAT_800fdfa0 + param_3 * 2);
      puVar1 = &UNK_800fc900;
    }
LAB_8004ad90:
    DAT_8010b294 = 0x80;
    DAT_8010b295 = 0;
    DAT_8010b296 = 0x80;
    DAT_8010b29c = puVar1 + uVar3;
    DAT_8010b2ac = 0x22;
    DAT_8010b2b4 = DAT_800e1110;
    DAT_8010b2b8 = param_4;
    return 0;
  }
  DAT_8010b2b8 = param_4;
  if (uVar3 < 0x201) {
    if (uVar3 == 0x100) {
      DAT_8010b2ae = 0xb9;
      DAT_8010b2b0 = 0x2003;
      if ((DAT_800e10ec & 0x40) == 0) {
        uVar3 = (uint)*(ushort *)(&DAT_800fa66c + param_3 * 2);
        puVar1 = &UNK_800fa394;
      }
      else {
        DAT_8010b2b0 = 0x6003;
        uVar3 = (uint)*(ushort *)(&DAT_800fa364 + param_3 * 2);
        puVar1 = &UNK_800f9fc8;
      }
      goto LAB_8004ad90;
    }
LAB_8004ae04:
    DAT_8010b2ae = (undefined2)((uint)param_1 >> 0x10);
    DAT_8010b296 = (byte)(param_2 >> 8) & 0x80;
    uVar3 = param_2 & 0xc00;
    DAT_8010b2ac = (undefined2)param_1;
    DAT_8010b2b0 = (ushort)param_2;
    if (uVar3 == 0x400) {
      if ((DAT_800e10ec & 0x40) == 0) {
        uVar3 = (uint)*(ushort *)(&DAT_800fc818 + param_3 * 2);
        puVar1 = &UNK_800fb530;
      }
      else {
        uVar3 = (uint)*(ushort *)(&DAT_800fdfa0 + param_3 * 2);
        puVar1 = &UNK_800fc900;
        DAT_8010b2b0 = DAT_8010b2b0 | 0x4000;
      }
    }
    else {
      if (0x400 < uVar3) {
        if (uVar3 != 0x800) {
          if (uVar3 == 0xc00) {
            DAT_8010b294 = 0x80;
            DAT_8010b295 = 0;
            DAT_8010b29c = (undefined *)param_3;
            DAT_8010b2b4 = DAT_800e1110;
            return 0;
          }
          DAT_8010b294 = 0x80;
          DAT_8010b295 = 0;
          DAT_8010b2b4 = DAT_800e1110;
          return 0;
        }
        if ((DAT_800e10ec & 0x40) != 0) {
          DAT_8010b2b0 = DAT_8010b2b0 | 0x4000;
        }
        DAT_8010b29c = *(undefined **)(DAT_800df92c + 0x3c);
        goto LAB_8004af6c;
      }
      if (uVar3 != 0) {
        DAT_8010b294 = 0x80;
        DAT_8010b295 = 0;
        DAT_8010b2b4 = DAT_800e1110;
        return 0;
      }
      if ((DAT_800e10ec & 0x40) == 0) {
        uVar3 = (uint)*(ushort *)(&DAT_800fa66c + param_3 * 2);
        puVar1 = &UNK_800fa394;
      }
      else {
        uVar3 = (uint)*(ushort *)(&DAT_800fa364 + param_3 * 2);
        puVar1 = &UNK_800f9fc8;
        DAT_8010b2b0 = DAT_8010b2b0 | 0x4000;
      }
    }
    DAT_8010b29c = puVar1 + uVar3;
  }
  else {
    if (uVar3 != 0x300) goto LAB_8004ae04;
    DAT_8010b2ac = 0x22;
    DAT_8010b2ae = 0xb9;
    DAT_8010b2b0 = 0x803;
    DAT_8010b296 = 0x80;
    if ((param_2 & 1) != 0) {
      DAT_8010b2b0 = 0x4803;
    }
    if ((DAT_800e10ec & 0x40) == 0) {
      DAT_8010b29c = *(undefined **)(DAT_800df92c + 0x3c);
    }
    else {
      DAT_8010b2b0 = DAT_8010b2b0 | 0x4000;
      DAT_8010b29c = *(undefined **)(DAT_800df92c + 0x3c);
    }
LAB_8004af6c:
    sVar2 = FUN_800844cc((int)*(short *)((int)DAT_8010b29c + param_3 * 2));
    DAT_8010b29c = (undefined *)((int)DAT_8010b29c + (int)sVar2);
  }
  return 0;
}
