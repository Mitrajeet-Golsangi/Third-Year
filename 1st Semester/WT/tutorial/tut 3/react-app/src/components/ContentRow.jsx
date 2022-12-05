import React from 'react';

const ContentRow = ({ seed, reverse }) => {
	return (
		<div className="row mb-4 p-4 shadow rounded">
			{reverse ? (
				<>
					<div className="col-md-4">
						<img
							className="img-fluid"
							src={`https://picsum.photos/1920/1080?random=${seed}`}
							alt="Random"
						/>
					</div>
					<div className="col-md-8 text-sm">
						Labore ipsum minim do culpa fugiat laboris officia dolor esse anim
						ipsum. Ea eu dolore sit laborum commodo. Proident eu ullamco
						voluptate fugiat. Aute cupidatat mollit et deserunt. Dolore aliqua
						ad nostrud nulla. Aliqua velit irure Lorem cillum sunt proident enim
						voluptate. In duis amet dolore excepteur irure laborum id amet
						exercitation fugiat adipisicing excepteur. Culpa do dolor mollit et
						aliquip fugiat cillum dolor voluptate quis officia magna nostrud
						proident. Exercitation commodo amet aliquip et labore Lorem mollit
						consequat. Exercitation aliqua sint magna deserunt proident do aute
						commodo esse est. Dolor laboris minim dolor commodo occaecat quis ea
						minim quis. Proident ut pariatur labore do eu dolor dolore enim.
						Ipsum voluptate esse eiusmod ipsum dolor est. Consequat excepteur
						non pariatur ad nisi. Et do nulla esse qui esse occaecat cillum. Id
						exercitation elit Lorem culpa consectetur tempor sint est tempor
						ullamco. Sit irure ea fugiat dolore sunt elit dolor duis eiusmod.
					</div>
				</>
			) : (
				<>
					<div className="col-md-8">
						Laborum laborum laborum amet voluptate non cupidatat cupidatat
						mollit reprehenderit Lorem. Aliqua officia magna aliquip voluptate
						reprehenderit nisi ex id qui dolore sint ut reprehenderit laborum.
						Ad Lorem nostrud aliqua sunt qui. Duis esse labore excepteur sint
						consectetur ut tempor in laborum reprehenderit. Commodo sint nostrud
						do nisi. Mollit ullamco sit ullamco nostrud Lorem est. Aliqua do
						sunt esse deserunt ad ea veniam et. Ut nulla irure excepteur ullamco
						quis veniam voluptate. Magna cupidatat qui consequat do enim non do
						esse eiusmod sint labore commodo. Dolor laboris veniam sint aliquip
						quis irure nostrud laborum mollit duis in cillum minim. Aute
						deserunt sint labore aliquip enim. Ut eu aliquip voluptate sit
						laborum nostrud cillum exercitation incididunt nulla nisi.
						Consectetur magna laboris voluptate pariatur commodo ullamco
						consequat qui. Dolore nostrud culpa esse Lorem ea culpa. Nisi do
						eiusmod nisi veniam. Excepteur culpa Lorem excepteur ad occaecat
						nulla aute laborum dolore exercitation exercitation. Officia eu
						nostrud cillum duis ea. Voluptate duis id dolore sit est consequat
						nisi sint proident enim. Ullamco ad adipisicing dolore eu ipsum
						incididunt minim tempor laboris et qui id nisi. Reprehenderit aute
						eu Lorem sit aliqua tempor magna velit adipisicing irure id
						cupidatat consequat. Consequat consectetur velit laborum dolor qui
						et est. Excepteur consectetur Lorem aute cupidatat veniam Lorem ex.
					</div>
					<div className="col-md-4">
						<img
							className="img-fluid"
							src={`https://picsum.photos/1920/1080?random=${seed}`}
							alt="Random"
						/>
					</div>
				</>
			)}
		</div>
	);
};

export default ContentRow;
