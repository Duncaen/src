/* autogenerated by dtc, do not edit */

	.globl	dt_blob_start
dt_blob_start:
_dt_blob_start:
	.globl	dt_header
dt_header:
_dt_header:
	/* magic */
	.byte 0xd0; .byte 0x0d; .byte 0xfe; .byte 0xed
	/* totalsize */
	.word	_dt_blob_abs_end - _dt_blob_start
	/* off_dt_struct */
	.word	_dt_struct_start - _dt_blob_start
	/* off_dt_strings */
	.word	_dt_strings_start - _dt_blob_start
	/* off_mem_rsvmap */
	.word	_dt_reserve_map - _dt_blob_start
	/* version */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x11
	/* last_comp_version */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x10
	/* boot_cpuid_phys */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x00
	/* size_dt_strings */
	.word	_dt_strings_end - _dt_strings_start
	/* size_dt_struct */
	.word	_dt_struct_end - _dt_struct_start
	.balign	8, 0
	.globl	dt_reserve_map
dt_reserve_map:
_dt_reserve_map:
/* Memory reserve map from source file */
	.long	0, 0
	.long	0, 0
	.globl	dt_struct_start
dt_struct_start:
_dt_struct_start:
	/* FDT_BEGIN_NODE */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x01
	.string	""
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x0e
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x00
	.byte 0x43; .byte 0x4e; .byte 0x33; .byte 0x78
	.byte 0x78; .byte 0x78; .byte 0x2f; .byte 0x43
	.byte 0x4e; .byte 0x35; .byte 0x78; .byte 0x78
	.byte	0x78
	.byte	0x0
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x06
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x15
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	.balign	4, 0
	/* FDT_BEGIN_NODE */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x01
	.string	"soc@0"
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x0b
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x21
	.byte 0x73; .byte 0x69; .byte 0x6d; .byte 0x70
	.byte 0x6c; .byte 0x65; .byte 0x2d; .byte 0x62
	.byte	0x75
	.byte	0x73
	.byte	0x0
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x2c
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x01
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x06
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x15
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x00
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x3d
	.balign	4, 0
	.globl	ciu
ciu:
	/* FDT_BEGIN_NODE */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x01
	.string	"ciu@1070000000000"
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x17
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x21
	.byte 0x63; .byte 0x61; .byte 0x76; .byte 0x69
	.byte 0x75; .byte 0x6d; .byte 0x2c; .byte 0x6f
	.byte 0x63; .byte 0x74; .byte 0x65; .byte 0x6f
	.byte 0x6e; .byte 0x2d; .byte 0x33; .byte 0x38
	.byte 0x36; .byte 0x30; .byte 0x2d; .byte 0x63
	.byte	0x69
	.byte	0x75
	.byte	0x0
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x00
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x44
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x59
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x10
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x6a
	.byte 0x00; .byte 0x01; .byte 0x07; .byte 0x00
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x00
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x00
	.byte 0x00; .byte 0x00; .byte 0x70; .byte 0x00
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x6e
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x01
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x74
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x01
	.balign	4, 0
	/* FDT_END_NODE */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	.globl	ciu_end
ciu_end:
	/* FDT_BEGIN_NODE */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x01
	.string	"mdio@1180000001800"
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x18
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x21
	.byte 0x63; .byte 0x61; .byte 0x76; .byte 0x69
	.byte 0x75; .byte 0x6d; .byte 0x2c; .byte 0x6f
	.byte 0x63; .byte 0x74; .byte 0x65; .byte 0x6f
	.byte 0x6e; .byte 0x2d; .byte 0x33; .byte 0x38
	.byte 0x36; .byte 0x30; .byte 0x2d; .byte 0x6d
	.byte 0x64; .byte 0x69; .byte 0x6f; .byte 0x00
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x06
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x01
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x04
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x15
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x00
	.balign	4, 0
	/* FDT_PROP */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x03
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x10
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x6a
	.byte 0x00; .byte 0x01; .byte 0x18; .byte 0x00
	.byte 0x00; .byte 0x00; .byte 0x18; .byte 0x00
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x00
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x40
	.balign	4, 0
	/* FDT_END_NODE */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	/* FDT_END_NODE */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	/* FDT_END_NODE */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x02
	/* FDT_END */
	.byte 0x00; .byte 0x00; .byte 0x00; .byte 0x09
	.globl	dt_struct_end
dt_struct_end:
_dt_struct_end:
	.globl	dt_strings_start
dt_strings_start:
_dt_strings_start:
	.string "model"
	.string "#address-cells"
	.string "#size-cells"
	.string "compatible"
	.string "interrupt-parent"
	.string "ranges"
	.string "interrupt-controller"
	.string "#interrupt-cells"
	.string "reg"
	.string "linux,phandle"
	.globl	dt_strings_end
dt_strings_end:
_dt_strings_end:
	.globl	dt_blob_end
dt_blob_end:
_dt_blob_end:
	.globl	dt_blob_abs_end
dt_blob_abs_end:
_dt_blob_abs_end:
